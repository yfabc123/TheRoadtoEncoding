#include <iostream>
#include <pthread.h>
using namespace std;

class A
{

public:
    static A *get()
    {
        if (a == nullptr)
        {
            pthread_mutex_lock(&lock);
            if (a == nullptr)
            {
                a = new A();
            }
            pthread_mutex_unlock(&lock);
        }

        return a;
    }

private:
    A()
    {
        cout << "唯一一次构造" << endl;
    }
    static A *a;
    static pthread_mutex_t lock;
};
A *A::a = nullptr;
pthread_mutex_t A::lock = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    A *one = A::get();
    cout << one << endl;
    A *two = A::get();
    cout << two << endl;

    return 0;
}
