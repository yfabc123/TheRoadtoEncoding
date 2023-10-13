#include <iostream>
using namespace std;
class Studet
{
public:
    Studet();
    Studet(const Studet &stu);
};
Studet::Studet()
{
    cout << "普通构造" << endl;
}
Studet::Studet(const Studet &stu)
{
    cout << "拷贝构造" << endl;
}
Studet fun(Studet par)
{
    Studet mnt = par;
    return mnt;
}
int main()
{
    Studet a;
    Studet b = fun(a);
    return 0;
}
