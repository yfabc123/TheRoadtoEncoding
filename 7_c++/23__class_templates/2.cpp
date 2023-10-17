#include <iostream>
using namespace std;
// 顺序表放什么数据类型不确定 所以使用抽象数据类型
template <typename T>
class SeqList
{
public:
    SeqList(int size)
    {
        if (size <= 0)
        {
            cout << "参数非法" << endl;
            return;
        }
        index = 0;
        this->size = size;
        buf = new T[size];
    }
    void addDate(const T &data)
    {
        if (index >= size)
        {
            cout << "顺序表满了" << endl;
            return;
        }
        buf[index++] = data;

        cout << "插入数据成功" << endl;
    }
    void delData(const T &data) // 删除指定元素并将后面数据前移动 最后索引提前
    {
        int j, i;
        for (i = 0, j = -1; i < index; i++)
        {

            if (buf[i] != data)
            {
                buf[++j] = buf[i];
            }
        }
        index = j + 1;
    }
    void showData()
    {
        for (int i = 0; i < index; i++)
        {

            cout << buf[i] << endl;
        }
    }
    ~SeqList()
    {

        if (index > 0)
        {
            cout << "触发析构" << endl;
            delete[] buf;
        }
        buf = NULL;
    }

private:
    T *buf;
    int size;
    int index; // 下一次要插入的索引位置
};
template <class T1, class T>

class B : public SeqList<T>
{
};

int main()
{
    SeqList<string> one(10);
    // one.addDate("2");

    one.showData();
    cout << "----------------" << endl;
    one.delData("2");
    one.addDate("1");
    one.showData();

    return 0;
}
