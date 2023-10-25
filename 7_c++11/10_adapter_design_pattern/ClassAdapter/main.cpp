#include "PowerAdapter.hpp"
#include "ChinaPlug.hpp"

int main()
{
	PowerAdapter *powerAdapter = new PowerAdapter;

	cout << powerAdapter->getOutput5V() << endl;
	
	return 0;
}
