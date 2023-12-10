#include <stdio.h>
int main(int argc, char *argv[])
{
	int num1, num2, num3;
	FILE *fp = fopen(argv[1], "r+");
	fscanf(fp, "herlwe");
	char buffer[64] = "1-2-3";
	num1 = 0, num2 = 0;
	num3 = 0;
	sscanf(buffer, "%d-%d-%d", &num1, &num2, &num3);
	printf("%d-%d-%d", num1, num2, num3);
}
