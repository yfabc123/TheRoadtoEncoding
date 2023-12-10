#include <stdio.h>
//需求 确定输入数字的长度 
int main()
{


int a=0;
int i=0;

scanf("%d",&a);

do{
	i++;
	a=a/10;
	
	
}while(a>0); 
printf("a的长度是%d",i) ;

return 0; 

}
