#include <stdio.h>
#include <stdlib.h>
int main() {
int number; 
int* p;
printf("«Î ‰»Î");
scanf("%d",&number);

p=(int*)malloc(number*sizeof(int));

for(int i=0;i<number;i++){
   
    scanf("%d",&p[i]);
    
}
for(int i=0;i<number;i++){
    printf("%d\n",p[i]);
}

//free(p);


	return 0;
}

 
