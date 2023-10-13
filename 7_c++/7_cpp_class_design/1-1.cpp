#include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
    void play(string name);
};
void student::play(string game_name)
{
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
    cout << "score:" << score << endl;
    cout << name << " play " << game_name << endl;
}
int main()
{
    student yefan;
    yefan.age = 27;
    yefan.name = "yefan";
    yefan.score = 60;
    yefan.play("dota2");

    return 0;
}
