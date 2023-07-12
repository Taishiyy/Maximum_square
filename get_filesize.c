#include "main.h"
#define BUFSIZE 100

unsigned int	get_filesize(char *filename)
{
	unsigned int	sum;
	int				read_amount;
	int				fd1;
	char			buf[100];

	fd1 = open(filename, O_RDONLY);
	if (fd1 == -1)
		return (0);
	sum = 0;
	while (1)
	{
		read_amount = read(fd1, buf, 100);
		if (read_amount == -1)
			return (0);
		if (read_amount != BUFSIZE)
		{
			sum += read_amount;
			break ;
		}
		else
			sum += 100;
	}
	close(fd1);
	return (sum);
}
