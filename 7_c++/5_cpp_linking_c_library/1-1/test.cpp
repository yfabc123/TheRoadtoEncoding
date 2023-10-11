#include <iostream>

#include <stdio.h>
#include "add.h"

int main()
{
    int result;
    result = add(10, 20); // addii -> add
    printf("result = %d\n", result);
    result = sub(10, 20); // subii -> sub
    printf("result = %d\n", result);
    return 0;
}
