#include <stdio.h>

namespace b
{
    int global = 200;
    void function()
    {
        printf("b.cpp global:%d\n", global);
    }
}