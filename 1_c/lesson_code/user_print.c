#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include "user_print.h"

// 指定位置输出 图形
// n---7图案中的选择某个图案
// m---4个方向中某个方向。
// x,y指定的坐标
// c  颜色
void print_mode_shape(int n, int m, int x, int y, int c)
{
	int i = 0;
	int xx = x;
	int yy = y;
	for (i = 0; i < 16; i++)
	{
		// 每经过4行,纵坐标 + 1 横坐标回到原来
		if (i != 0 && i % 4 == 0)
		{
			yy += 1;
			xx = x;
		}

		if (shape[n][m][i] == 1)
		{
			printf("\033[%d;%dH\033[%dm[]\033[0m", yy, xx, c);
		}
		xx += 2;
	}
	fflush(NULL);
}

// 清除指定位置图形
// n---7图案中的选择某个图案
// m---4个方向中某个方向。
// x,y指定的坐标
// c  颜色
void erase_last_shape(int n, int m, int a, int b)
{
	int i = 0;
	int xx = a;
	int yy = b;

	for (i = 0; i < 16; i++)
	{
		if (i != 0 && i % 4 == 0) // 这个if用来确认坐标的
		{
			yy++;
			xx = a;
		}
		if (shape[n][m][i] == 1)
		{
			printf("\033[%d;%dH  \033[0m", yy, xx);
		}
		xx += 2;
	}
	fflush(NULL);
}

// 右侧准备生成下一个位置的图形并输出。
void print_next_shape()
{
	// 擦除上一次图形  第一次的图形和方向都是0  后续调用的话就是根据下次赋的值来的
	erase_last_shape(next_num, next_mode, next_x, next_y);

	next_num = random() % 7;
	next_mode = random() % 4;
	next_color = random() % 7 + 40;

	// 在指定位置输出图形
	print_mode_shape(next_num, next_mode, next_x, next_y, next_color);

	fflush(NULL);
}

// int matrix[24][28] = {0}  存储图形
void store_current_shape()
{
	int m_line = dynamic_y - 6;
	int m_column = dynamic_x - 12;
	int i = 0;

	for (i = 0; i < 16; i++)
	{
		if (i != 0 && i % 4 == 0)
		{
			m_line++;
			m_column = dynamic_x - 12;
		}

		//[][] 一个元素也就是一个方框占两个坐标点
		if (shape[dynamic_num][dynamic_mode][i] == 1)
		{
			matrix[m_line][m_column] = dynamic_color;
			matrix[m_line][m_column + 1] = dynamic_color;
		}
		m_column += 2;
	}
}

// 碰撞检测，如果撞上返回1， 否则返回0
int judge_shape(int num, int mode, int x, int y)
{
	int m_line = y - 6;
	int m_column = x - 12;

	int i = 0;

	for (; i < 16; i++)
	{
		if (i != 0 && i % 4 == 0)
		{
			m_line++;
			m_column = x - 12;
		}
		// 该像素点有数据
		if (shape[num][mode][i] == 1)
		{
			// 该像素点有颜色
			if (matrix[m_line][m_column] != 0)
			{
				return 1;
			}
		}
		m_column += 2;
	}
	return 0;
}

void init_new_shape()
{
	dynamic_num = next_num;
	dynamic_mode = next_mode;
	dynamic_color = next_color;

	dynamic_x = init_x;
	dynamic_y = init_y;

	print_mode_shape(next_num, next_mode, dynamic_x, dynamic_y, dynamic_color);
}
