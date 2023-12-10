#include "client.h"

int main(void)
{
	client_init();
	//publish("hello","ABCDE");
	subscribe("hello");
	
	while(1){}

	return 0;
}
