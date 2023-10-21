#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Test
{
public:
    void TestWork(int index)
    {
        std::cout << a << std::endl;
    }
    void TestWork(int *index)
    {
        std::cout << "TestWork 2" << std::endl;
    }

private:
    string a{"hello" };
};

int main()
{
    Test test;
    test.TestWork(nullptr);
    vector<int> v{1, 2, 3};
    map<string, int> m{{"yefan", 1}, {"c", 2}};
    Test t;
    t.TestWork(0);

    return 0;
}