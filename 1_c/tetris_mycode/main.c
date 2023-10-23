#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
// 初始化图形坐标
int init_x = 24;
int init_y = 6;

// 右侧提示模块图形信息
int next_x = 46;
int next_y = 8;
int next_shape;
int next_direction;
int next_color;

// 当前图形信息(因为坐标和方向这三个变量需要基于当前信息变化的)
int cur_x;
int cur_y;
int cur_shape;
int cur_direction;
int cur_color;

int element[7][4][18] =
    {
        {
            {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2}, //
            {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2}, //
            {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2}, //[][]
            {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2}, //[][]
        },
        {
            {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0}, //[]  [][][][]
            {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3}, //[]
            {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0}, //[]
            {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3}, //[]
        },
        {
            {0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //  []    []      [][][]     []
            {1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1}, //[][][]  [][]      []     [][]
            {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //        []                 []
            {0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1}  //
        },
        {
            {1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //[][]       []
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1}, //  [][]   [][]
            {1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //         []
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1}, //
        },
        {
            {0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //  [][]   []
            {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1}, //[][]     [][]
            {0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //           []
            {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1}, //
        },
        {
            {0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //    []   []    [][][]  [][]
            {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2, 1}, //[][][]   []    []        []
            {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2}, //         [][]            []
            {1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1}  //
        },
        {{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},  //[]       [][]  [][][]      []
         {1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1},  //[][][]   []        []      []
         {1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},  //         []              [][]
         {0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2, 1}}, //
};

// 指定坐标位置 指定图案形状 指定方向 指定颜色输出图形 需要5个参数
/*
[] 占两个横坐标
 */
void print_mode_shape(int x, int y, int shape, int direction, int color)
{
    // printf("\33[2J");

    int xx = x;
    int yy = y;
    for (int i = 0; i < 16; i++)
    {
        if (element[shape][direction][i] == 1) // 横坐标:2*(i%4)+xx  纵坐标:i/4+yy
        {
            printf("\033[%d;%dH\033[%dm[]\033[0m", i / 4 + yy, 2 * (i % 4) + xx, color);
            //  printf("\033[%d;%dH\033[%dm[]", i / 4 + yy, 2 * (i % 4) + xx, color);
        }
    }
    fflush(NULL);
}
/* ui界面设计:
游戏空间
宽度:14个小坐标点 也就是28个光标 或者(由于终端的光标宽度只有高度的一半为了形成正方形更美观一点于是)
高度:24个小坐标点 24个光标
右边提示界面容纳坐标点:7*6

边框: 上边框纵坐标为5 加上容纳游戏的24个坐标 在加上下边框 所有左边范围是 5到30
 */
void print_start_ui()
{
    printf("\33[2J");
    // 打印上下两条横杠 每一行输出24个坐标点也就是48个光标
    for (int i = 0; i < 47; i++)
    {
        // printf("\33[43m \33[%d;%dH\33[0m", 5, 10 + i);  //不知道为啥把颜色控制放前面会有点小问题..
        //  printf("\33[43m \33[%d;%dH\33[0m", 30, 10 + i);
        printf("\33[%d;%dH\33[43m \33[0m", 5, i + 10);
        printf("\33[%d;%dH\33[43m \33[0m", 30, i + 10);
    }
    // 打印左中右3条竖杠 每一列输出26次

    for (int i = 0; i < 26; i++)
    {
        printf("\33[%d;%dH\33[43m  \33[0m", 5 + i, 10);
        printf("\33[%d;%dH\33[43m  \33[0m", 5 + i, 40);
        printf("\33[%d;%dH\33[43m  \33[0m", 5 + i, 56);
    }

    // 打印分数和下次图形提示的分割线
    for (int i = 0; i < 16; i++)
    {
        printf("\33[%d;%dH\33[43m \33[0m", 12, i + 42);
    }
    // // 输出分数和等级
    //  18  45
    printf("\33[%d;%dH分数:\33[0m", 18, 45);
    // 22  45
    printf("\33[%d;%dH等级:\33[0m", 22, 45);

    fflush(NULL);
}

/*
游戏板块随机生成图形
 */
void print_game_shape()
{

    cur_shape = random() % 7;
    cur_direction = random() % 4;
    cur_color = random() % 8 + 40;
    cur_x = init_x;
    cur_y = init_y;
    print_mode_shape(init_x, init_y, cur_shape, cur_direction, cur_color);
}
// 提示板块生成的图形
void print_next_shape()
{
    next_shape = random() % 7;
    next_direction = random() % 4;
    next_color = random() % 8 + 40;

    print_mode_shape(next_x, next_y, next_shape, next_direction, next_color);
}

// 游戏初始化
void init_game()
{
}

// 自动下落
void move_down()
{
    erase();
    cur_y++;
    print_mode_shape(cur_x, cur_y, cur_shape, cur_direction, cur_color);
}
void move_left()
{
    erase();
    cur_x--;
    print_mode_shape(cur_x, cur_y, cur_shape, cur_direction, cur_color);
}
void move_right() // 每隔1秒下落一个坐标轴
{
    erase();
    cur_x++;
    print_mode_shape(cur_x, cur_y, cur_shape, cur_direction, cur_color);
}
void do_alarm()
{
    move_down();
    alarm(1);
}

void erase()
{

    int xx = cur_x;
    int yy = cur_y;
    for (int i = 0; i < 16; i++)
    {
        if (element[cur_shape][cur_direction][i] == 1) // 横坐标:2*(i%4)+xx  纵坐标:i/4+yy
        {
            printf("\033[%d;%dH  \033[0m", i / 4 + yy, 2 * (i % 4) + xx);
            //  printf("\033[%d;%dH\033[%dm[]", i / 4 + yy, 2 * (i % 4) + xx, color);
        }
    }
    fflush(NULL);
}

// 设置毫秒定时器
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

int main()
{
    srand((unsigned)time(NULL));

    print_start_ui();
    print_game_shape();
    print_next_shape();
    signal(SIGALRM, do_alarm);
    alarm_us(100000);

    while (1)
    {
        getchar();
    }

    return 0;
}