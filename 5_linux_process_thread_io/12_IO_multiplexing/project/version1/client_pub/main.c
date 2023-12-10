#include "client.h"

int main(void)
{
	client_init();
	publish("hello","ABCDE");
	//subscribe("hello");

	return 0;
}
