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

    (*this).hour = hour;
}
void Time::setMinute(int minute)
{
    this->minute = minute;
}
void Time::setSecond(int second)
{
    this->second = second;
}
void Time::output()
{
    cout << "设置的时间时:" << hour << ":" << minute << ":" << second << endl;
}
// 静态区创建对象
Time time2;
int main()
{
    // 栈区创建
    Time time1;

    time1.setHour(11);
    time1.setMinute(35);
    time1.setSecond(59);
    time1.output();
    // 静态区创建
    time2.setHour(14);
    time2.setMinute(14);
    time2.setSecond(14);
    time2.output();

    // 堆区创建对象
    Time *time3 = new Time;
    time3->setHour(14);
    time3->setMinute(40);
    time3->setSecond(12);
    time3->output();
    delete time3;

    return 0;
}
