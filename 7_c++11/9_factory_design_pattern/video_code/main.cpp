#include "SimpleFactory.hpp"

int main()
{
	AbstractPhone *android = SimpleFactory::getPhone("Android");
	AbstractPhone *apple   = SimpleFactory::getPhone("Apple");

	android->call();
	android->message();

	cout << "--------------------" << endl;

	apple->call();
	apple->message();
	
	return 0;
}
