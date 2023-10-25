#include "Proxy.hpp"
#include "RealGirl.hpp"

int main()
{
	Girl *girl1 = new RealGirl("婷婷");
	Girl *girl2 = new RealGirl("雅雅");
	girl1->marry(1000);
	Proxy *proxy = new Proxy;
	proxy->setMarryGirl(girl1);
	proxy->setMarryGirl(girl2);

	proxy->marry(100);

	cout << "----------------" << endl;

	proxy->marry(100);

	return 0;
}
