#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//��ȡ1��35�������
int f1() {
	int a= rand()%35+1;
	return a;
}
//��ȡ1��12�������
int f2() {
	int a= rand()%12+1;
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
	//����ǰ5����
	for(int i=0; i<5; i++) {
		int temp=f1();

		while(f3(a,length,temp))  {
			temp=f1();//�������������������ʱ������������
		}
		a[i]=temp;
	}
	//���ɺ�2����
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


