#include <stdio.h>
int main() {

	printf("请输入：");
	int a=0;
	int i=2;
	scanf("%d",&a);
	while(a%i!=0) {
		i++;


	}
	if(i==a) {
		printf("素数");

	} else {
		printf(" 不是素数");
	}



	return 0;

}
