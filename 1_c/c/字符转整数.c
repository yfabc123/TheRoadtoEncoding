#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_to_int(char *str)
{
	int len = strlen(str);
	int sum = 0;

	for (int i = 0; *(str + i) != '\0'; i++)
	{
		sum = sum * 10 + *(str + i) - '0'; // 技巧 上次结果*10+这次结果 ,与'0'的差值就是当前整数
	}
	return sum;
}

int main()
{
	char a[8] = {0};
	scanf("%s", a);
	printf("%d", str_to_int(a));

	return 0;
}
