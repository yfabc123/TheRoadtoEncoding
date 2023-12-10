#include <stdio.h>
int main(){
	int max=0;
	printf("请输入三个数");
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c); 
	
	if(a>=b){
		max=a;
		}
		else {
		max=b;				
		}
		
		if(c>=max){
			max=c;
		}
		printf("最大的数是%d",max);


	return 0;
} 
