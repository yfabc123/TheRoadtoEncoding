#include <iostream>
using namespace std;

class Device
{
public:
    virtual void transfer()
    {
        cout << "传输" << endl;
    }
};
class Bluetooth : public Device
{
public:

    void transfer()
    {
        cout << "蓝牙传输" << endl;
    }
};

class Four_g : public Device
{
public:

    void transfer()
    {
        cout << "4g传输" << endl;
    }
};

class Wifi : public Device
{
public:

    void transfer()
    {
        cout << "wifi传输" << endl;
    }
};
void fun(Device *device)
{
    device->transfer();
}

int main()
{
    Bluetooth b;
    Four_g four_g;
    Wifi wifi;

    fun(&b);
    fun(&four_g);
    fun(&wifi);

    return 0;
}
