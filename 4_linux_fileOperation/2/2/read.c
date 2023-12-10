#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
int main(int argc, char *argv[])
{

	int fd;
	char buffer[64] = {0}; // 用来保存读到缓冲区的数
	ssize_t rbytes;		   // 整型
	if (argc != 2)
	{
		fprintf(stderr, "usage:<%s> <pathname>\n ", argv[0]);
		return -1;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open():");
		return -1;
	}
	rbytes = read(fd, buffer, 10);
	if (-1 == rbytes)
	{
		perror("read():");
		return -1;
	}
	printf("Buffer:%s\n", buffer);
	close(fd);
	return 0;
}
