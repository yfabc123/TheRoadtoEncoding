#include "head.h"
#define debug
struct person
{
    char *name;
    int age;
};
void *cthread(void *parr)
{
    static struct person person1;
    person1.age = 28;
    // person1.name="yefan";//学了几个月c语言怎么写出这样的代码 字符串能赋值给数组？
    person1.name = "yefan";
    pthread_exit((void *)&person1);
}
int main()
{
#ifdef debug
    void *rec = NULL;
    pthread_t tid;
    pthread_create(&tid, NULL, cthread, NULL);
    pthread_join(tid, (void **)&rec);
    printf("%d-%s", ((struct person *)rec)->age, ((struct person *)rec)->name);
#endif
    return 0;
}