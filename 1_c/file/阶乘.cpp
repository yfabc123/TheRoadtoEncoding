#include <stdio.h>
//Çó½×³Ë  1*2*3*4*n 
int main(){
	int a=0;
	printf("ÇëÊäÈë£º\n"); 
	scanf("%d",&a);
	int result=1;

//for(int i=1;i<=a;i++){
//	result=result*i;
//	
//}
	

//		int i=1;
//	while(i<=a){
//		result=result*i;
//		i++;
//		
//		
//	}


for ( int i=10; i> 1; i /=2 ) {
    printf("%d ", i++);
}

printf("%d",result);

return 1;


} 
