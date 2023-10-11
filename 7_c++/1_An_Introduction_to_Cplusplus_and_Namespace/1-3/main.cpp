#include <stdio.h>

namespace a
{
    extern int globa1;
    extern void function();

}
namespace b
{
    extern int globa1;
    extern void function();

}

int main()
{

    a::function();
    printf("-----------\n");
    b::function();

    return 0;
}
