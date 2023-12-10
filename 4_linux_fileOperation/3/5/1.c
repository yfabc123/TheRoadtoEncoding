#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

	FILE *fp = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "Usage : ./a.out <filename>\n");
		exit(-1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		exit(-1);
	}

	char ch;

	for (;;)
	{
		ch = fgetc(fp);
		if (ch == EOF)
			break;

		fputc(ch, stdout);
	}

	fclose(fp);

	return 0;
}
