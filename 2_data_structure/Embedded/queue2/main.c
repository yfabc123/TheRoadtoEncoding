#include "head.h"

#define MAX_MIN_STACK 5
#define MAX_MIN5_STACK 12
#define MAX_HOUR_STACK 12


int max_ball_queue = 0;
int ball[100] = {0};
int half_day = 0;

linkqueue_t *ball_queue = NULL;
linkstack_t *min_stack = NULL;
linkstack_t *min5_stack = NULL;
linkstack_t *hour_stack = NULL;

void init_ball_clock()
{
	half_day = 0;
	ball_queue = create_empty_linkqueue();
	min_stack = create_empty_linkstack();
	min5_stack = create_empty_linkstack();
	hour_stack = create_empty_linkstack();
}

datatype_linknode pop_to_ball_queue(linkstack_t *s)
{
	datatype_linknode data = pop_linkstack(s);
	
	while(!is_empty_linkstack(s))
		enter_linkqueue(ball_queue,pop_linkstack(s));

	return data;
}

void do_ball_clock()
{
	if(is_empty_linkqueue(ball_queue))
		enter_linkqueue(ball_queue,++max_ball_queue);

	push_linkstack(min_stack,out_linkqueue(ball_queue));

	if(MAX_MIN_STACK == min_stack->n)
		push_linkstack(min5_stack,pop_to_ball_queue(min_stack));
	if(MAX_MIN5_STACK == min5_stack->n)
		push_linkstack(hour_stack,pop_to_ball_queue(min5_stack));
	if(MAX_HOUR_STACK == hour_stack->n)
	{
		enter_linkqueue(ball_queue,pop_to_ball_queue(hour_stack));	
		half_day++;
	}
}

void print_ball_clock()
{
	int day = half_day / 2;
	int hour = hour_stack->n + 12*(half_day % 2);
	int min = min_stack->n + min5_stack->n * 5;
	printf("day %d %02d:%02d\n",day,hour,min);
}

void store_ball_seq()
{
	int n = 0;
	linknode_t *p = NULL;
	p = ball_queue->front->next;
	while(NULL != p)
	{
		ball[n++] = p->data;
		p = p->next;
	}
}

int check_ball_seq()
{
	int n = 0;
	linknode_t *p = NULL;
	p = ball_queue->front->next;
	while(NULL != p)
	{
		if(ball[n++] != p->data)
			break;
		p = p->next;
	}

	if(n == max_ball_queue) 
		return 1;
	return 0;
}

int main()
{

	//question 1
	//每分钟计数若球不够自动添加球，循环60×12次，即12小时，最终得到所需球数量
	init_ball_clock();

	for(int i = 0;i < 60*12;i++){
		do_ball_clock();
	}
	printf("最少需要球数 = %d\n",max_ball_queue);

	//question 2
	//根据question1得到的结果，按编号0-26依次加入球队列，并记录其顺序
	//每分钟时间计数检查是否与最初顺序相同，否则继续时间计数，最终得出所需时间
	init_ball_clock();

	for(int i = 0;i < max_ball_queue;i++)
		enter_linkqueue(ball_queue,i);

	store_ball_seq();

	do{
		do_ball_clock();
	}while(!check_ball_seq());


	printf("最少需要时间: ");
	print_ball_clock();

	return 0;
}
