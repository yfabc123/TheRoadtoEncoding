#include <stdio.h>

int main() {
	int a=0;//����̨��ȡ����
	int i=0;//��¼����Ĵ���
	int arr[]={0};
	int sum=0;
 	int avg;

	while(a!=-1) {

		printf("������:");
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
	        printf("���д���ƽ��������%d\n",arr[a]);
	        
        }
	}
 printf("���鳤��%d",sizeof(arr));
	return 0;
}
