#include <iostream>
using namespace std;

int my_swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
    return 0;
}

int my_swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
    return 0;
}
int main(void)
{
    double a = 1.1;
    double b = 2.2;
    cout << a << " " << b << endl;
    my_swap(a, b);
    cout << a << " " << b << endl;
    cout <<"================================"<< endl;
    string c = "linux";
    string d = "c";
    cout << c << " " << d << endl;
    my_swap(c, d);
    cout << c << " " << d << endl;
    return 0;
}
