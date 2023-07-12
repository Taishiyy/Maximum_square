#include "main.h"

bool	firstline_check(char *buffer, t_data *map_data, int *index)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	num = 0;
	if (buffer[0] < '1' && buffer[0] > '9')
		return (false);
	while (buffer[i] != '\n')
		i++;
	*index = i + 1;
	while (j < i - 3)
	{
		if (buffer[j] >= '0' && buffer[j] <= '9')
		{
			num = num * 10 + buffer[j] - '0';
			j++;
		}
		else
			return (false);
	}
	map_data->row = num;
	firstline_set(buffer[i - 3], buffer[i - 2], buffer[i - 1], map_data);
	return (true);
}

bool	firstline_set(char emp, char obs, char ful, t_data *map_data)
{
	if (!(emp != obs && emp != ful && obs != ful))
		return (false);
	if (emp > 31 && emp < 127)
		map_data->empty = emp;
	if (obs > 31 && obs < 127)
		map_data->obstacle = obs;
	if (ful > 31 && ful < 127)
		map_data->full = ful;
	return (true);
}

bool	second_line_check(char *buffer, t_data *map_data, int *index)
{
	int	count;
	int	i;

	count = 0;
	i = *index;
	if (!(map_symbol_check(buffer, map_data, *index)))
		return (false);
	while (buffer[i] != '\n')
	{
		i++;
		count++;
	}
	*index = i + 1;
	map_data->col = count;
	return (true);
}

bool	line_count(char *buffer, t_data *map_data, int *index)
{
	int	i;
	int	count;

	i = *index;
	count = 0;
	while (buffer[i] != '\n')
	{
		count++;
		i++;
	}
	*index = i + 1;
	if (count != map_data->col)
		return (false);
	return (true);
}

bool	map_symbol_check(char *buffer, t_data *map_data, int index)
{
	while (buffer[index] != '\n')
	{
		if (buffer[index] == map_data->empty
			|| buffer[index] == map_data->obstacle)
			index++;
		else
			return (false);
	}
	return (true);
}
