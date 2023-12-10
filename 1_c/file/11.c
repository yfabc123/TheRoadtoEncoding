#include <stdio.h>
void f(int a,int b) {
	int temp=0;
	temp=a;
	a=b;
	b=temp;
}
int main() {
	int a[3]= {1,2,3};
	int *p=a;
//*a=a[0]=*p=p[0]
	printf("%p",p[0]);
	printf("%p",*p);
	printf("%p",*a);
	printf("%p",a[0]);






	return 0;
}


