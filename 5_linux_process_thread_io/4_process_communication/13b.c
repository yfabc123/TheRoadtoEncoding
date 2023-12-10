#include "head.h"
int main()
{
    msgctl(1, IPC_RMID, NULL);
    return 0;
}