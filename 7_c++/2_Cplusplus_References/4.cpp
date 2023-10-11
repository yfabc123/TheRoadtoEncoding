#include <iostream>

using namespace std;

int main(void)

{

    int a = 10;
    int b = 1;
    int &new_a = a; // 常引用
    new_a = b;

    cout << new_a;
    return 0;
}
