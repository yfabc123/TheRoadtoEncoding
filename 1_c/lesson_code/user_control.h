#ifndef _USER_CONTROL_H_
#define _USER_CONTROL_H_
#include <stdio.h>
#include <termios.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

//用户的分数
extern int user_score;
//用户的层次
extern int user_level;
extern int tm;
extern int score_x;   //分数的横坐标
extern int score_y;   //分数的纵坐标   
extern int level_x;   //等级的横坐标           
extern int level_y;   //等级的纵坐标              
extern int getch();
extern void alarm_us(int n);
extern void key_control();
extern void fall_down();
extern int move_left(int n,int m);
extern int move_right(int n,int m);
extern int change_shape();
extern void game_over();
extern void recover_attribute();
extern int move_down(int num,int mode);
extern void print_matrix();
extern void print_score_level();
#endif
