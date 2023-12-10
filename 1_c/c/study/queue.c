#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data[10];   
    
    int front;
    int rear;
}SqQueue;

int InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
    return 1;
}
//插入数据前 判断队列满条件是尾指针后面是头指针
void EnQueue(SqQueue *Q,int a){
    if ((Q->rear-Q->front+1+10)%10<9)
    {
        Q->data[Q->rear]=a;
        Q->rear=(Q->rear+1)%10;
    }
    
}
//删除前 判队列空条件头指针等于尾指针 
void f(SqQueue *q){
    if (q->front==q->rear)
    {
        printf("队列为空不能删除");
        
    }else
    
    q->data[q->front]=0;
    q->front=(q->front+1)%10;
}



int main(){

return 0;
}