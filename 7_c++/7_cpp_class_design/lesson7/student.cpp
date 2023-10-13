#include <stdio.h>
#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	int age;
	int score;

public:
	Student();
	Student(const string &name,int age,int score);
	void setName(const string &name);
	void setAge(int _age);
	void setScore(int _score)
	{
		score = _score;
	}

	void playGame(const char *game);
};


Student::Student(const string &name,int age,int score):name(name),age(age),score(score)
{
	cout << "Student(const string &name,int age,int score)" << endl;
#if 0	
	this->name = name;
	this->age  = age;
	this->score = score;
#endif
}

#if 1
Student::Student()
{
	cout << "Student()" << endl;
	name = "";
	age  = 0;
	score = 0;
}
#endif 

void Student::setName(const string &name)
{
	//参数name = 参数name
	//name = name;
	this->name = name;
}

void Student::setAge(int _age)
{
	age = _age;
}

void Student::playGame(const char *game)
{
	cout << this->name <<" play " << game << endl;
	cout << "name : " << name << endl;
	cout << "score: " << score << endl;
	cout << "age  : " << age << endl; 
}

Student gstu;//静态区对象

int main(int argc, const char *argv[])
{
	Student stu("xiaoming",20,100);//栈区对象

	stu.playGame("King");
	
	cout << "---------------------" << endl;

	stu.setName("xiaoming");
	stu.setAge(10);
	stu.setScore(90);
	stu.playGame("King");
	
	cout << "--------------------------" << endl;
	Student *pstu;

	pstu = new Student("tiechui",0,30);//堆区对象 
#if 0
	pstu->setName("tiechui");
	pstu->setScore(0);
	pstu->setAge(30);
#endif 

	pstu->playGame("King");

	delete pstu;

	return 0;
}
