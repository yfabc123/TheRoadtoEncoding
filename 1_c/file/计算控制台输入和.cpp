#include <stdio.h>
int main() {
	int temp=0;
	int   number=0;
	int   sum=0;
	printf   ("�����룺");

	scanf("%d",&temp);
	while (temp!=-1) {
		sum=temp+sum;
		number++;
		printf("�����룺");

		scanf("%d",&temp);


	}
	printf("һ��%d���� ����%d",number,sum);


	return 1;
}
