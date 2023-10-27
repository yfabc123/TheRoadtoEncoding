#include <iostream>

using namespace std;

int main()
{
    printf("\033[2J");
    fprintf(stderr, "\033[0;0H\033[32m_\033[0m");
    fprintf(stderr, "\033[0;0H\033[32m_\033[0m");

    return 0;
}