#include <stdio.h>
int main() {
	int temp=0;
	int   number=0;
	int   sum=0;
	printf   ("请输入：");

	scanf("%d",&temp);
	while (temp!=-1) {
		sum=temp+sum;
		number++;
		printf("请输入：");

		scanf("%d",&temp);


	}
	printf("一共%d个数 和是%d",number,sum);


	return 1;
}
