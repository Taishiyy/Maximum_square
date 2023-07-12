#include "main.h"

static int	g_index;
static int	g_row_count;
static int	g_col_count;

void	ft_free(int ***grid)
{
	while (--g_row_count >= 0)
		free((*grid)[g_row_count]);
	free(*grid);
}

int	get_map(char *buffer, t_data *map_data, int ***grid)
{
	*grid = (int **)malloc(sizeof(int *) * (map_data->row + 1));
	if (*grid == NULL)
		return (0);
	while (g_row_count < map_data->row)
	{
		g_col_count = 0;
		g_index++;
		(*grid)[g_row_count] = (int *)malloc(sizeof(int) * (map_data->col + 1));
		if (**grid == NULL)
			return (0);
		while (g_col_count < map_data->col)
		{
			if (buffer[g_index] == map_data->empty)
				(*grid)[g_row_count][g_col_count] = 0;
			else
				(*grid)[g_row_count][g_col_count] = 1;
			g_index++;
			g_col_count++;
		}
		g_row_count++;
	}
	return (1);
}

int	adv_prep(t_data *map_data, int file_size, char *filename, int ***grid)
{
	int		fd;
	int		rd;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * file_size);
	if (buffer == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (!open_check(fd, buffer))
		return (0);
	rd = read(fd, buffer, file_size);
	if (!check_all_error(fd, rd, buffer, map_data))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	while (buffer[g_index] != '\n')
		g_index++;
	if (!get_map(buffer, map_data, grid))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	close(fd);
	return (1);
}

int	start(char *filename)
{
	t_data	map_data;
	int		file_size;
	int		**grid;

	g_index = 0;
	g_row_count = 0;
	file_size = get_filesize(filename);
	map_data.filesize = file_size;
	if (!adv_prep(&map_data, file_size, filename, &grid))
	{
		ft_free(&grid);
		return (0);
	}
	solve_init(&map_data, &grid);
	return (1);
}
