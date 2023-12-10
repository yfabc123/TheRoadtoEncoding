#include <stdio.h>
struct point{
    int x;
    int y;
};
struct point * getStruct(struct point *p){    
    scanf("%d",&p->x);
    scanf("%d",&p->y);                
           
}

void output(struct point p){
    printf("%d,%d\n",p.x,p.y);
}
int main(void){
    struct point a={0,0}; 
    output(a); 
    getStruct(&a);          
    output(a);
    return 0;
}


