/* 实现适配器 能转换所有插座的电压转成5v */
#include "Adapter.hpp"
#include "UsPlug.hpp"
#include "ChinaPlug.hpp"
using namespace std;

int main()
{
    Adapter adapter;
    ChinaPlug one;

    cout << one.outputv() << endl;
    adapter.change(&one);
    cout << adapter.output5v() << endl;
    UsPlug two;

    cout << two.outputv() << endl;
    adapter.change(&two);
    cout << adapter.output5v() << endl;
    return 0;
}
