#include <stdio.h>
int main() {

	int a;
	int b;
	scanf("%d %d",&a,&b);
	int i=1;//������
	int max=0;//��Լ��
	while(i<=a&&i<=b) {
		if(a%i==0&&b%i==0) {
			max=i;


		}
		i++;
	}
	
	printf("%d",max);
	return 0;
}
