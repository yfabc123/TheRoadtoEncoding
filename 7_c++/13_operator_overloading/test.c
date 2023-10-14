#include <stdio.h>
#include <stdlib.h>
typedef struct person
{
    int age;
    int score;
} person_t;

person_t *fun(person_t para)
{
    person_t temp;
    temp.age = para.age + 1;
    temp.score = para.score + 1;
    return &temp;
}
int main()
{
    person_t one = {27, 90};
    person_t *two = fun(one);

    printf("%d %d", two->age, two->score);

    return 0;
}