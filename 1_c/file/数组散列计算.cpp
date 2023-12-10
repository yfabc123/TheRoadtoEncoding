#include <stdio.h>
int main()
{
	int arr[20];
	int a = 0;
	int b = 0; // 数组的个数
	// 存储控制台输入的数
	while (a != -1)
	{
		printf("输入:");
		scanf("%d", &a);
		arr[b] = a;
		b++;
	}

	// 统计
	int e = 0;
	for (int c = 0; c < 10; c++)
	{
		for (int d = 0; d < b; d++)
		{
			if (arr[d] == c)
			{
				e++;
			}
		}
		printf("%d出现的个数是%d\n", c, e);
		e = 0;
	}

	return 0;
}
