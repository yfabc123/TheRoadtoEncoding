#include <stdio.h>
int main()
{
	int arr[20];
	int a = 0;
	int b = 0; // ����ĸ���
	// �洢����̨�������
	while (a != -1)
	{
		printf("����:");
		scanf("%d", &a);
		arr[b] = a;
		b++;
	}

	// ͳ��
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
		printf("%d���ֵĸ�����%d\n", c, e);
		e = 0;
	}

	return 0;
}
