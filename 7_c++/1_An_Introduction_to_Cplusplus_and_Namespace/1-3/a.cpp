#include <stdio.h>

namespace a
{
    int global = 100;
    void function()
    {
        printf("a.cpp global:%d\n", global);
    }
}