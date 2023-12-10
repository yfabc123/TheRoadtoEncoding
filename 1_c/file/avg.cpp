#include <stdio.h>

int main() {
	int a=0;//控制台获取数据
	int i=0;//记录输入的次数
	int arr[]={0};
	int sum=0;
 	int avg;

	while(a!=-1) {

		printf("请输入:");
		scanf("%d",&a);
		if(a!=-1) {
			arr[i]=a;
			i++;
			sum=sum+a;

		}

	}
	avg=sum/i;

	for(int a=0; a<i; a++) {
	    if(arr[a]>avg){
	        printf("所有大于平均数的有%d\n",arr[a]);
	        
        }
	}
 printf("数组长度%d",sizeof(arr));
	return 0;
}
