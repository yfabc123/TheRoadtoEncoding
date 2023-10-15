#ifndef _COMPUTER_H__
#define _COMPUTER_H__
#include <iostream>
using namespace std;
class Computer
{
public:
    Computer(const string brand)
    {
        cout << "Computer(const string brand)" << endl;

        this->brand = brand;
    }
    ~Computer()
    {

        cout << "~Computer()" << endl;
    }
    string getBrand() const
    {
        return this->brand;
    }

private:
    string brand;
};
#endif
