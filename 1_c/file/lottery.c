#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//��ȡ1��16�������
int f1() {
	int a= rand()%33+1;
	return a;
}
//��ȡ1��33�������
int f2() {
	int a= rand()%16+1;
	return a;
}
//ȷ��������û����ͬ����
int f3(int arr[],int length,int number) {
	int a=0;//Ĭ�� �����
	for(int i=0; i<length; i++) {

		if(arr[i]==number) {
			a=1;//�����
			break;
		}
	}
	return a;

}
int main() {
	srand((unsigned int)time(NULL));
	int a[7];
	int length=sizeof(a)/sizeof(a[0]);
	//����ǰ6����
	for(int i=0; i<6; i++) {
		int temp=f1();
		while(f3(a,length,temp))  {
			temp=f1();//�������������������ʱ������������
		}
		a[i]=temp;
	}
	//���ɵ�7����
	a[6]= f2();
	for( int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		printf("%d    ",a[i]);
	}
	return 0;

}


