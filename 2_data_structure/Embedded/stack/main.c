#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int top;
    char arr[100];
} stack1;

// 创建栈
stack1 *create()
{
    stack1 *s = (stack1 *)malloc(sizeof(stack1));
    s->top = -1;//鼠标指向最上面的数据
    memset(s, '\0', sizeof(s->arr));
    return s;
}
// 存数据
void insert(stack1 *s, char *a)
{

    for (int i = 0;*(a+i)!='\0'; i++)
    {
        s->arr[s->top+1]=*(a+i);
        s->top++;
    }

}
// 遍历数据
void pritf_data(stack1 *s){
    int i=s->top;
    while (i>-1)
    {
        printf("%c ",s->arr[i]);   
        i--;
    }
    
}
int main()
{
stack1 *s=create();
char arr[]={'a','n','i','h','c',' ','e','v','o','l',' ','I'};

insert(s,arr);
pritf_data(s);


    return 0;
}