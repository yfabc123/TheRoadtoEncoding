#include <stdio.h>

enum color {red ,yellow,green};

void f(enum color c){
    printf("%d\n",c);
}
int main(){
enum color t=red;
scanf("%d",&t);
//printf("%d",t);
f(t);

return 0;
}


