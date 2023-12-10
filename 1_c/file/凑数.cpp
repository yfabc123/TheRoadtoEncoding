#include <stdio.h>
int main()
{
	int money;
	scanf("%d", &money);
	int boolean = 0;
	for (int i = 0; 0.1 * i <= money; i++)
	{

		for (int j = 0; 0.2 * j <= money; j++)
		{
			for (int x = 0; 2 * x <= money; x++)
			{
				if ((0.1 * i + 0.2 * j + 2 * x) == money)
				{
					printf("%d个一角%d个2角%d个2元可以凑成%d\n", i, j, x, money);
					boolean = 1;

					goto out;
				}
			}
		}
	}

out:

	return 0;
}
