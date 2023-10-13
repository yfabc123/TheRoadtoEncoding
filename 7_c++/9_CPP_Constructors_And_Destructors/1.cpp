#include <iostream>
using namespace std;

class Student
{

public:
    //  Student();
    Student(string name, int age, int score);

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
// Student::Student()
// {
//     cout << "调用构造函数" << endl;
//     this->age = 0;
//     this->name = "";
//     this->score = 0;
// }
Student::Student(string name, int age, int score)
{
    this->name = name;
    this->age = age;
    this->score = score;
}

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
  //  Student stu;
    Student yefan = Student("yefan", 28, 90);
    Student yefan1("yefan", 28, 90);

    // yefan.play("dota2");

    // yefan.setAge(28);
    // yefan.setName("yefan");
    // yefan.setScore(90);
    // yefan.play("dota2");

    return 0;
}
