#include <stdio.h>
//��ȡĳ�����������е�λ��

void find(int a,int arr[]) {
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
		if(arr[i]==a) {
			printf("%d�������е�%d��λ����",a,i+1);
		}


	}


}



int main() {
	int arr[5]= {1,2,3,9,18};

	printf("%d",sizeof(arr)/sizeof(arr[0]));


	return 0;
}


