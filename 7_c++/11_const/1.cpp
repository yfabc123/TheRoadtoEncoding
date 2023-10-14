#include <iostream>
#include <string.h>
using namespace std;
class String
{

public:
	String(const char *str = NULL, int max = 100);
	String(const String &other); // 拷贝构造
	~String(void);

	void show(void);
	static void showMemoryUsed(void); // 静态成员函数
private:
	char *str;
	const int maxLen;	   // 常成员变量
	static int memoryUsed; // 静态成员变量
};

int String::memoryUsed = 0; // 类外进行初始化

String::String(const char *str, int max) : maxLen(max)
{
	if (str == NULL)
	{
		this->str = NULL;
	}
	else
	{
		int len = strlen(str) + 1;
		this->str = new char[len];
		strcpy(this->str, str);
	}
}
