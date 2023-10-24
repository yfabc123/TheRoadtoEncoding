
#include <iostream>
using namespace std;

class HungrySingleton
{
public:
    static HungrySingleton *getInstance()
    {

        return object;
    }
    void show()
    {
        cout << "show()" << endl;
    }

private:
    HungrySingleton()
    {
        cout << "构造" << endl;
    }
    HungrySingleton(const HungrySingleton &other)
    {
        *this = other;
    }

    static HungrySingleton *object;
};
HungrySingleton *HungrySingleton::object = new HungrySingleton;//不太理解为社么可以在类外初始化
int main()
{

    cout << "main" << endl;
    HungrySingleton *obj = HungrySingleton::getInstance();
    cout << obj << endl;

    HungrySingleton *obj1 = HungrySingleton::getInstance();
    cout << obj1 << endl;

    return 0;
}
