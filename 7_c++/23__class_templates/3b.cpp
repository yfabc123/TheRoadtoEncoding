#include <iostream>

using namespace std;
template <typename T, int size>
class SeqList
{
public:
    SeqList()
    {
    }
    int addData(const T &data);
    void show(void) const;

private:
    T *buf;
    int index;
};

int main(int argc, char const *argv[])
{
    SeqList<string, 10> list;
    return 0;
}
