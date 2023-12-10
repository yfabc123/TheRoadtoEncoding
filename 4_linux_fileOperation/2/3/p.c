#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

// a==>b
int main()
{
	char *file_a = "a.txt";
	char *file_b = "b.txt";
	int fd_a;
	int fd_b;
	ssize_t read_a;
	ssize_t write_b;
	char temp[5] = {0};
	fd_a = open(file_a, O_RDWR | O_CREAT, 0777);
	if (-1 == fd_a)
	{
		perror("open:");
	}

	fd_b = open(file_b, O_RDWR | O_CREAT, 0777);
	if (-1 == fd_b)
	{
		perror("open_b");
	}
	while (read_a != 0)
	{
		read_a = read(fd_a, temp, sizeof(temp));
		printf("%s-%ld\n", temp, read_a);
		if (-1 == read_a)
		{
			perror("read_a:");
		}
		if (0 == read_a)
		{
			break;
		}
		write_b = write(fd_b, temp, read_a);
		if (-1 == write_b)
		{
			perror("write_b:");
		}
	}

	close(fd_a);
	close(fd_b);
}
