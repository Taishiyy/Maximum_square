#include "main.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	filename[256];
	if (argc == 1)
	{
		i = read(0, filename, 256);
		filename[i - 1] = 0;
		start(filename);
	}
	i = 1;
	while (i < argc)
	{
		start(argv[i]);
		i++;
	}
	return (0);
}
