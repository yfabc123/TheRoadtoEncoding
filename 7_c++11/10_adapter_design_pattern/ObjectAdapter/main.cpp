#include "PowerAdapter.hpp"
#include "ChinaPlug.hpp"
#include "UsPlug.hpp"
int main()
{
	ChinaPlug *chinaPlug = new ChinaPlug;
	PowerAdapter *powerAdapter = new PowerAdapter;
	powerAdapter->setPlug(chinaPlug);

	cout << powerAdapter->getOutput5V() << endl;

	UsPlug *usplug = new UsPlug;
	powerAdapter->setPlug(usplug);
	cout << powerAdapter->getOutput5V() << endl;

	return 0;
}
