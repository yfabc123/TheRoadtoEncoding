#include <iostream>
using namespace std;

int main()
{
    fprintf(stderr, "\033[0;0H");

    fprintf(stderr, "\033[0;0H\033[42m  \033[0m\n");
    fprintf(stderr, "\033[3;3H\033[41m  \033[0m\n");
     fprintf(stderr, "\033[0;0H");

    return 0;
}
