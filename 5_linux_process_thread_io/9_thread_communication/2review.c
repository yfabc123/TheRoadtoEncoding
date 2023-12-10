// 设计一个结构 struct perosn ,包含名字与年龄，在子线程中定义结构体变量，并传递给主线程进行打印
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
typedef struct
{
    char name[32];
    int age;
} Person;
void *subThread(void *para)
{
    Person *person = (Person *)malloc(sizeof(Person));
    person->age = 28;
    strcpy(person->name, "叶凡");
    pthread_exit(person);
}
int main()
{
    pthread_t tid;
    void *a=NULL;
    pthread_create(&tid, NULL, subThread, NULL);
    pthread_join(tid, &a);
    printf("%d %s", ((Person *)a)->age, ((Person *)a)->name);
    printf("%d %s", ((Person *)a)->age, ((Person *)a)->name);
    return 0;
}