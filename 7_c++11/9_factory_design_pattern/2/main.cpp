#include "AndroidFactory.hpp"
#include "AppleFactory.hpp"

int main  ()
{
	AndroidFactory *androidFactory = new AndroidFactory;
	AbstractPhone *android = androidFactory->getPhone();
	AppleFactory  *appleFactory = new AppleFactory;
	AbstractPhone *apple   = appleFactory->getPhone();

	android->call();
	android->message();

	cout << "--------------------" << endl;

	apple->call();
	apple->message();
	
	return 0;
}
