#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//获取1到35的随机数
int f1() {
	int a= rand()%35+1;
	return a;
}
//获取1到12的随机数
int f2() {
	int a= rand()%12+1;
	return a;
}
//确认数组有没有相同的数
int f3(int arr[],int length,int number) {
	int a=0;//默认 不相等
	for(int i=0; i<length; i++) {

		if(arr[i]==number) {
			a=1;//有相等
			break;
		}
	}
	return a;

}
int main() {
	srand((unsigned int)time(NULL));
	int a[7];
	int length=sizeof(a)/sizeof(a[0]);
	//生成前5个数
	for(int i=0; i<5; i++) {
		int temp=f1();

		while(f3(a,length,temp))  {
			temp=f1();//当随机数出现在数组中时继续重新生成
		}
		a[i]=temp;
	}
	//生成后2个数
	a[5]=f2();
	int temp=f2();
	while(a[5]==temp) {
	    temp=f2();
    }
	a[6]=temp;
	
	for( int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		printf("%d   ",a[i]);
	}


	return 0;

}


