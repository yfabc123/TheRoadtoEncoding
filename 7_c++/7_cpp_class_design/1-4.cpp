#include <iostream>
using namespace std;

class Time
{
public:
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    void output();

private:
    int hour;
    int minute;
    int second;
};
void Time::setHour(int hour)
{

    this->hour = hour;
}
void Time::setMinute(int minute)
{
   (*this).minute = minute;
}
void Time::setSecond(int second)
{
    this->second = second;
}
void Time::output()
{
    cout << "设置的时间时:" << hour << ":" << minute << ":" << second << endl;
}

int main()
{
    Time time;
    time.setHour(11);
    time.setMinute(35);
    time.setSecond(59);
    time.output();
    return 0;
}
