#include <stdio.h>
int main(int argc, char *argv[])
{
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "%s", argv[0]);
		return -1;
	}

	file = fopen(argv[1], "r+");
	if (NULL == file)
	{
		perror("fopen:");
	}
	printf("%s",file->_IO_read_base);
	fclose(file);
}
