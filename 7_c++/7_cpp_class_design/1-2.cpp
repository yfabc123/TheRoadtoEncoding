#include <iostream>
using namespace std;

class Student
{

public:
    void play(string name);
    void setName(const string name);
    void setAge(const int age);
    void setScore(const int socre)
    {
        this->score = socre;
    }

private:
    string name;
    int age;
    int score;
};
void Student::play(string game_name)
{
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "score:" << score << endl;
    cout << name << " play " << game_name << endl;
}
void Student::setName(const string name)
{
    this->name = name;
}

void Student::setAge(const int age)
{
    this->age = age;
}

int main()
{
    Student yefan;
    yefan.setAge(28);
    yefan.setName("yefan");
    yefan.setScore(90);
    yefan.play("dota2");

    return 0;
}
