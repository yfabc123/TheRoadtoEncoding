#include "head.h"


//================================链式队列===================

//创建空链式队列
linkqueue_t *create_empty_linkqueue()
{
	//创建队列头
	linkqueue_t *q = NULL;
	q = (linkqueue_t *)malloc(sizeof(linkqueue_t));
	if(NULL == q)
	{
		printf("malloc is fail!");
		return NULL;
	}
	memset(q,0,sizeof(linkqueue_t));

	//创建头结点
	linknode_t *head = NULL;
	head = (linknode_t *)malloc(sizeof(linknode_t));
	memset(head,0,sizeof(linknode_t));
	head->next = NULL;

	//使头指针和尾指针指向头结点
	q->front = head;
	q->rear = head;

	return q;
}

//判断队列是否为空
int is_empty_linkqueue(linkqueue_t *q)
{
	return q->front == q->rear ? 1 : 0;
}

//向队列添加数据
void enter_linkqueue(linkqueue_t *q,datatype_linknode data)
{
	//创建新结点
	linknode_t *p_new_node = NULL;
	p_new_node = (linknode_t *)malloc(sizeof(linknode_t));
	
	//将数据赋给新结点
	p_new_node->data = data;

	//将新结点添加为队列尾结点
	p_new_node->next = q->rear->next;
	q->rear->next = p_new_node;

	//更新尾指针
	q->rear = p_new_node;
	
	return;
}

//从队列取出数据
datatype_linknode out_linkqueue(linkqueue_t *q)
{
	//新建指向头结点下一结点的指针
	linknode_t *p_node = q->front->next;

	//保存队列头结点下一结点的数据
	datatype_linknode data = p_node->data;
	
	//更新头指针
	q->front->next = p_node->next;
	if(NULL == q->front->next)
		q->rear = q->front;

	//释放原头结点下一结点的内存
	free(p_node),p_node = NULL;

	//返回数据
	return data;
}


//===========================链式栈==========================

//创建空链式栈
linkstack_t *create_empty_linkstack()
{
	//创建栈头
	linkstack_t *s = NULL;
	
	s = (linkstack_t *)malloc(sizeof(linkstack_t));

	if(NULL == s)
	{
		printf("malloc is fail!");
		return NULL;
	}
	memset(s,0,sizeof(linkstack_t));

	s->top = NULL;
	s->n = 0;

	return s;
}

//判断链式栈是否为空
int is_empty_linkstack(linkstack_t *s)
{
	return s->top == NULL ? 1 : 0;
}

//压入数据
void push_linkstack(linkstack_t *s,datatype_linknode data)
{
	//创建新结点
	linknode_t *p_new_node = NULL;
	p_new_node = (linknode_t *)malloc(sizeof(linknode_t));
	if(NULL == p_new_node){
		printf("malloc is fail!");
		return;
	}

	//更新头结点                            
	p_new_node->data = data;
	p_new_node->next = s->top;
	s->top = p_new_node;
	s->n++;
}

//弹出数据
datatype_linknode pop_linkstack(linkstack_t *s)
{
	//创建指向栈头的指针
	linknode_t *temp;
	temp = s->top;

	//保存栈头数据
	datatype_linknode data;
	data = temp->data;
	

	//释放栈头
	s->top = temp->next;
	free(temp),temp = NULL;

	s->n--;
	
	return data;
}

//取得栈头数据
datatype_linknode get_top_data(linkstack_t *s)
{
	return s->top->data;
}
