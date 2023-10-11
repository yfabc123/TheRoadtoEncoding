#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	int *p = (int *)malloc(4);
	int *q = new int;

	cout << "p value : " << p << endl;
	cout << "q value : " << q << endl;

	*p = 100;
	*q = 200;

	cout << "*p : " << *p << endl;
	cout << "*q : " << *q << endl;

	free(p);
	delete q;

	cout << "---------------" << endl;
	int *m = new int[3];

	for (int i = 0; i < 3; i++)
	{
#if 0
		*m = i + 1;
		m ++;
#endif
		m[i] = i + 1; //*(m + i) = i + 1
	}

	for (int i = 0; i < 3; i++)
	{
		cout << i << ":" << *(m + i) << endl;
	}

	delete[] m;

	return 0;
}
