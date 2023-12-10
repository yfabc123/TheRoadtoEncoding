#include <stdio.h>

int main() {
	int a=0;//控制台输入的数
	scanf("%d",&a);
	int temp=0;
	int sum=0;
	while(a>0) {

		temp=a%10+temp*10;

		a=a/10;

}

		printf("%d",temp);





	return 0;
}

