#include <stdio.h> 

int main(){
	printf("������һ����");
	int a=0;
	scanf("%d",&a);
	for (int i=2;i<a;i++){
		int j=2;
		while(i%j!=0){
			j++;
			
		}
		if(j==i){
			printf("%d\n",i);
		}
		
	}
	return 0;
}
