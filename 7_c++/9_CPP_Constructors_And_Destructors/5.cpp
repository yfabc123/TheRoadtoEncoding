#include <iostream>

using namespace std;

class Test
{
public:
    Test(int size)
    {
        data = new int[size];
        max_index = size;
        index = 0;
    }

    ~Test()
    {
        delete data;
    }

    void insert(int data)
    {
        if (index < max_index)
            this->data[index++] = data;
    }

    void show(void)
    {
        for (int i = 0; i < index; i++)
        {
            cout << *data << endl;
            data++;
        }
    }

private:
    int index;
    int *data;
    int max_index;
};

int main(void)
{
    int i;
    Test *t = new Test(5);
    for (i = 0; i < 10; i++)
    {
        t->insert(i + 1);
    }

    t->show();

    return 0;
}
