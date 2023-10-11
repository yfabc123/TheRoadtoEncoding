#include <iostream>
#include <string>
using namespace std;

void get_mem(string **p)
{
    *p = new string[10];
}

void write_data(string *p)
{
    for (int i = 0; i < 10; i++)
    {

        int a = i;                                     // 个位 十位
        *(p + i) = "0x" + to_string(a) + to_string(a); // 转成字符串并拼接
    }
}

void out_put(string *p)
{

    for (int i = 0; i < 10; i++)
    {
        cout << *(p + i) << endl;
    }
}
int main()
{
    string *addr = NULL;
    cout << "原地址:" << addr << endl;
    get_mem(&addr);
    cout << "新地址:" << addr << endl;
    write_data(addr);
    out_put(addr);
    cout << "============" << endl;
    delete[] addr;
   // free(addr);
    cout << addr[4];

    return 0;
}
