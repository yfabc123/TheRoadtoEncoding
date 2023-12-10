//º∆À„ 1+1/2+1/3+...1/n 
#include <stdio.h>
int main(){

	int n;
	double sum=0.0;
	int i=1;
	scanf("%d",&n);
	while(i<=n){
	
		
		if(i%2==0){
		sum=sum-1.0/i;
		} else {
		sum=sum+1.0/i;
		}
		i++;
		
	}
	 printf("%f",sum);
	return 0;
}
