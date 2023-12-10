#include <stdio.h>
//求给定数组最大最小值
void minmax(int a[],int len,int *min,int *max) {
	*max=a[0];
	*min=a[0];
	for (int i=0; i<len; i++) {
		if(a[i]<*min) {
			*min=a[i];
		}
		if(a[i]>*max) {
			*max=a[i];
		}
	}

}
int main() {
	int a[]= {132,3,4,11,23,2,0};
	int min ,max;
	minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
	printf("min=%d,max=%d\n",min,max);
	return 0;
}

