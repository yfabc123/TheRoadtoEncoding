#include <stdio.h>
//获取某个数在数组中的位置

void find(int a,int arr[]) {
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
		if(arr[i]==a) {
			printf("%d在数组中第%d的位置上",a,i+1);
		}


	}


}



int main() {
	int arr[5]= {1,2,3,9,18};

	printf("%d",sizeof(arr)/sizeof(arr[0]));


	return 0;
}


