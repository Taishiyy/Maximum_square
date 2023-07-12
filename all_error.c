#include "main.h"

static int	g_count_line;

bool	check_loop(char *buffer, t_data *map_data, int *index)
{
	if (!map_symbol_check(buffer, map_data, *index))
		return (false);
	if (!line_count(buffer, map_data, index))
		return (false);
	return (true);
}

bool	check_all_error(int fd, int rd, char *buffer, t_data *map_data)
{
	int	index;

	index = 0;
	g_count_line = 0;
	if (!read_check(fd, rd, buffer))
		return (false);
	if (g_count_line == 0 && !firstline_check(buffer, map_data, &index))
		return (false);
	g_count_line += 1;
	if (g_count_line == 1 && !(second_line_check(buffer, map_data, &index)))
		return (false);
	g_count_line += 1;
	while (g_count_line <= map_data->row)
	{
		if (!check_loop(buffer, map_data, &index))
			return (false);
		g_count_line += 1;
	}
	if (index == map_data->filesize)
		return (true);
	else
		return (false);
}