#include <stdio.h>
struct date {
    int year;
    int month;
    int day;
    
};
int main(){
    
struct date a;
a.month=01;
a.day=02;
a.year=2022;
struct date b={2022,12};
struct date c;
c=b;

printf("%p\n",&a); 
printf("%p\n",&b);
printf("%p\n",&c); 
return 0;
}


