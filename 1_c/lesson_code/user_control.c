#include "user_control.h"
#include "user_print.h"

struct termios tm_old;

// 获取一个字符，不回显  w
int getch()
{
	struct termios tm;
	// 保存正常  输入属性 到 tm_old
	tcgetattr(0, &tm_old);
	// 获取原始输入属性
	cfmakeraw(&tm);
	// 设置原始输入属性
	tcsetattr(0, 0, &tm);
	// 不回显的获取一个字符
	int ch = getchar();
	// 恢复正常输入属性
	tcsetattr(0, 0, &tm_old);

	return ch;
}

void recover_attribute()
{
	// 恢复正常输入属性
	tcsetattr(0, 0, &tm_old);
}

// 微秒定时器,当定时器启动后，每隔一段时间会发送SIGALRM信号
void alarm_us(int n)
{
	struct itimerval value;

	// 设置定时器启动的初始化值n
	value.it_value.tv_sec = 0;
	value.it_value.tv_usec = n;

	// 设置定时器启动后的间隔数
	value.it_interval.tv_sec = 0;
	value.it_interval.tv_usec = n;

	// 1s后启动定时器，同时发出SIGALRM信号
	// 每间隔5S发送一次SIGALRAM信号
	setitimer(ITIMER_REAL, &value, NULL);
}

void print_matrix()
{
	int i, j;

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 28; j += 2)
		{
			if (matrix[i][j] == 0)
			{
				printf("\33[%d;%dH  \33[0m", i + 6, j + 12);
			}
			else
			{
				printf("\33[%d;%dH\33[%dm[]\33[0m", i + 6, j + 12, matrix[i][j]);
			}
		}
	}
	return;
}

// 输出分数  输出等级
void print_score_level()
{
	printf("\33[%d;%dH分数:%d\33[0m", score_y, score_x, user_score);
	printf("\33[%d;%dH等级:%d\33[0m", level_y, level_x, user_level);
	fflush(NULL);
}

// matrix[24][28]
void destory_cond_line()
{
	int i, j, k;
	int flag = 0;

	for (i = 0; i < 24; i++)
	{
		flag = 1; // 满行标志,如果为1满,0表示不满
		for (j = 1; j < 28; j++)
		{
			if (matrix[i][j] == 0)
			{
				flag = 0;
				break;
			}
		}

		// 说明第行满了
		if (flag == 1)
		{
			user_score += 10;
			if (user_score % 100 == 0)
			{
				user_level++;
				tm /= 2;
				alarm_us(tm);
			}

			// 删除i行,整体下移
			for (k = i; k > 0; k--)
			{
				for (j = 0; j < 28; j++)
				{
					matrix[k][j] = matrix[k - 1][j];
				}

				print_matrix();
				print_score_level();
			}
		}
	}
}
int move_down(int num, int mode)
{
/* (dynamic_y + (4 - shape[num][mode][17]) - 1 >= 29)代码含义:当前图形的最低点

  */
	if ((dynamic_y + (4 - shape[num][mode][17]) - 1 >= 29) ||
		judge_shape(num, mode, dynamic_x, dynamic_y + 1))
	{
		// 已经触底  或 越界,不能再向下移动
		store_current_shape();

		// 根据存储的数据,生成新的图形
		init_new_shape();

		// 消除满足条件的行
		destory_cond_line();

		// 右侧生成下一个新的图片
		print_next_shape();

		return 1;
	}
	// 清除现有图形
	erase_last_shape(num, mode, dynamic_x, dynamic_y);
	dynamic_y++;
	print_mode_shape(num, mode, dynamic_x, dynamic_y, dynamic_color);

	return 0;
}

void fall_down()
{
	int ret;
	while (1)
	{
		// 不断调用下降函数
		ret = move_down(dynamic_num, dynamic_mode);
		if (ret == 1)
			return;
	}
}

// int n = dynamic_num;
// int mode = dynamic_mode;
int move_left(int n, int m)
{
	// 边界检测
	if (dynamic_x <= 12)
		return 1;

	// 碰撞检测
	if (judge_shape(n, m, dynamic_x - 2, dynamic_y))
		return 1;

	erase_last_shape(n, m, dynamic_x, dynamic_y);
	dynamic_x -= 2;
	print_mode_shape(n, m, dynamic_x, dynamic_y, dynamic_color);
	return 0;
}

// int n = dynamic_num;
// int mode = dynamic_mode;
int move_right(int n, int m)
{
	// 边界检测
	if (dynamic_x + 2 * (4 - shape[n][m][16]) - 1 >= 39)
		return 1;

	// 碰撞检测
	if (judge_shape(n, m, dynamic_x + 2, dynamic_y))
		return 1;

	erase_last_shape(n, m, dynamic_x, dynamic_y);
	dynamic_x += 2;
	print_mode_shape(n, m, dynamic_x, dynamic_y, dynamic_color);
	return 0;
}

int change_shape()
{
	int m = (dynamic_mode + 1) % 4;

	// 右侧越界判断
	if (dynamic_x + 2 * (4 - shape[dynamic_num][m][16]) - 1 > 39)
		return 1;

	// 右侧越界判断
	if (dynamic_y + 2 * (4 - shape[dynamic_num][m][17]) - 1 > 29)
		return 1;

	erase_last_shape(dynamic_num, dynamic_mode, dynamic_x, dynamic_y);
	dynamic_mode = m;
	print_mode_shape(dynamic_num, dynamic_mode, dynamic_x, dynamic_y, dynamic_color);
}

void game_over()
{
	printf("\33[32;9H************ Game Over***********************************\33[0m");
	printf("\33[25h");
	printf("\n\n");
}

//^[[A
//^[ ESC \33
//[
// A
// B
// D
// C
/* 疑问:为什么 输入esc检测不到.. */
void key_control()
{
	int ch;
	while (1)
	{
		ch = getch();
		if (ch == 'q' || ch == 'Q')
		{
			break;
		}
		else if (ch == '\r')
		{
			// 图形直接到底
			fall_down();
		}
		else if (ch == '\33')
		{
			ch = getch();
			if (ch == '[')
			{
				ch = getch();
				switch (ch)
				{
				case 'A': // 上
					change_shape();
					break;
				case 'B': // 下
					move_down(dynamic_num, dynamic_mode);
					break;
				case 'C': // 右
					move_right(dynamic_num, dynamic_mode);
					break;
				case 'D': // 左
					move_left(dynamic_num, dynamic_mode);
					break;
				default:
					break;
				}
			}
		}
	}
	game_over();
}
