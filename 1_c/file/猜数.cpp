#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	srand((unsigned int)time(NULL));
	int ret = rand()% 10;//对10取余可得到10以内的数 
	printf("%d\n", ret);


	int a;
	int num=1;
	printf("请输入你猜的数:") ;
	scanf("%d",&a);

while(a!=ret){
	if(a<ret){
		printf("猜小了");
	}
	else if(a>ret){
	printf("猜大了");
	} 
	printf("请重新输入:");
	scanf("%d",&a); 
	num++;
	
}
printf ("恭喜你终于猜对了,猜了%d",num
);
	return 0;

}

