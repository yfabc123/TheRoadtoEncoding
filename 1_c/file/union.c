#include <stdio.h>

typedef struct abc
{
	int a;
	char b[sizeof(int)];
} ONE;

int main()
{
	ONE one;
	one.a = 1234;
	for (int i = 0; i < 4; i++)
	{

		printf("%02hhX", one.b[i]);
	}

	return 0;
}
