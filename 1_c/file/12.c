#include <stdio.h>
void f(int *a,int *b) {
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main() {
	int a=3;
	int b=4;
	printf("%d--%d\n",a,b);

	f(&a,&b);
	printf("%d--%d",a,b);

	return 0;
}


