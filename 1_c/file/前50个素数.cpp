#include <stdio.h>

int main()
{
	printf("������һ����");
	int a = 0; // ��ǰ���ٸ�����
	scanf("%d", &a);
	int number = 0;
	int i = 2;
	while (number < a)
	{
		int j = 2;

		while (i % j != 0)
		{
			j++;
		}
		if (j == i)
		{
			number++;
			printf("%d\n", i);
		}
		i++;
	}

	return 0;
}
