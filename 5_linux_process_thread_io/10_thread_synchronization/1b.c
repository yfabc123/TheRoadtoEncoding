#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
// 首先这个程序预期是输入参数的2倍 因为两个进程都进行了global++但是结果并不是这样
static int global = 0; // 临界资源
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 定义互斥锁
void *do_thread(void *arg)
{
    int loops = *(int *)arg;
    int i, tmp = 0;
    for (i = 0; i < loops; i++) // 临界区
    {
        pthread_mutex_lock(&mutex); // 竞争锁 一旦竞争成功 获取临界资源访问资格 否则阻塞
        // 本例中故意写麻烦一点 多引入变量 为了让最后线程并发异常效果明显
        tmp = global;
        tmp++;
        global = tmp;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    int err, i = 0;
    pthread_t tid[2] = {0};
    int loops = 0;
    if (argc != 2)
    {
        fprintf(stderr, "Usage : < %s > < count loops>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    loops = atoi(argv[1]); // 把字符串转成int
    for (i = 0; i < 2; i++)
    {
        err = pthread_create(&tid[i], NULL, do_thread, &loops);
        if (err != 0)
        {
            fprintf(stderr, "[ERROR] pthread_create(): < %s > \n", strerror(err));
            exit(EXIT_FAILURE);
        }
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    printf("global = %d\n", global);
    return 0;
}
