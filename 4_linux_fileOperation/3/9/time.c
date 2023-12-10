#include <stdio.h>
#include <time.h>

// 获取系统时间，按照 <2022-5-8 23::15:00> 格式写入到文件中
int main(int a, char *b[])
{
	time_t t;
	time(&t);
	struct tm *ptm = localtime(&t);

	FILE *fp = fopen(b[1], "w+");

	printf("%d-%d-%d %d::%d:%d", ptm->tm_year + 1900,
		   ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
}
