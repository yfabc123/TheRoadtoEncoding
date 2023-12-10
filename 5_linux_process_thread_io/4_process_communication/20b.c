#include "head.h"

#define pathname "."
#define proj_id 2
int main()
{
    // 创建ipc key
    key_t key_shm = ftok(pathname, proj_id);
    // 创建共享内存
    int shmid = shmget(key_shm, 256, IPC_CREAT);
    // 映射共享内存和进程虚拟内存
    void *p = shmat(shmid, NULL, 0);
    // 打开文件
    FILE *fp1 = NULL;
    fp1 = fopen("./test_copy.png", "w+");
    fwrite(p,1,256,fp1);

    return 0;
}