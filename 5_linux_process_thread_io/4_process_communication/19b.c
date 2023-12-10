#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PATHNAME "."
#define PRO_ID 100
#define SZ 256
int main(void)
{
     key_t key;
     int shmid, ret;
     void *addr = NULL;
     key = ftok(PATHNAME, PRO_ID);
     if (key == -1)
     {
          perror("[ERROR] key(): ");
          exit(EXIT_FAILURE);
     }
     shmid = shmget(key, SZ, IPC_CREAT | 0666);
     if (shmid == -1)
     {
          perror("shmid(): ");
          exit(EXIT_FAILURE);
     }
     printf("shmid = %d\n", shmid);
     addr = shmat(shmid, NULL, 0);
     if (addr == (void *)-1)
     {
          perror("[ERROR] shmat(): ");
          return -1;
     }
     memset(addr, '1', 10);
     shmdt(addr);
     return 0;
}
