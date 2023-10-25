/* 实现适配器 能转换所有插座的电压转成5v */
#include "Adapter.hpp"
#include "UsPlug.hpp"
#include "ChinaPlug.hpp"
using namespace std;

int main()
{
    Adapter adapter;
    ChinaPlug one;
    cout << adapter.outputv() << endl;

    adapter.output5v();
    UsPlug two;

    cout << two.outputv() << endl;
    adapter.output5v();
    return 0;
}
