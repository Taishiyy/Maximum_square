#include "main.h"

bool	open_check(int fd, char *buffer)
{
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		free(buffer);
		return (false);
	}
	return (true);
}

bool	read_check(int fd, int rd, char *buffer)
{
	if (rd == -1)
	{
		free(buffer);
		close(fd);
		return (false);
	}
	return (true);
}
