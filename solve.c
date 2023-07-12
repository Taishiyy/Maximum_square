#include "main.h"

static int	g_ans_row;
static int	g_ans_col;
static int	g_max_size;

int	bit_min_get(int *ul, int *u, int *l)
{
	int	min;

	min = (*ul & ((*ul - *u) >> 31)) | (*u & (~(*ul - *u) >> 31));
	min = (min & ((min - *l) >> 31)) | (*l & (~(min - *l) >> 31));
	return (min + 1);
}

void	print_ans(t_data *map_data, int ***grid)
{
	int	i;
	int	j;
	int	u_row;
	int	u_col;

	u_row = g_ans_row - (g_max_size - 1);
	u_col = g_ans_col - (g_max_size - 1);
	i = 0;
	while (i < map_data->row)
	{
		j = 0;
		while (j < map_data->col)
		{
			if ((u_row <= i && i <= g_ans_row) && (u_col <= j
					&& j <= g_ans_col))
				write(1, &map_data->full, 1);
			else if ((*grid)[i][j] == 0)
				write(1, &map_data->obstacle, 1);
			else
				write(1, &map_data->empty, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	get_max_size(t_data *map_data, int ***grid)
{
	int	i;
	int	j;
	int	max;

	max = (*grid)[0][0];
	i = 0;
	while (i < map_data->row)
	{
		j = 0;
		while (j < map_data->col)
		{
			if ((*grid)[i][j] > max)
			{
				max = (*grid)[i][j];
				g_ans_row = i;
				g_ans_col = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

void	solve(t_data *map_data, int ***grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->row)
	{
		j = 0;
		while (j < map_data->col)
		{
			if ((*grid)[i][j] == 1)
				(*grid)[i][j] = 0;
			else if (i == 0 || j == 0)
				(*grid)[i][j] = 1;
			else
				(*grid)[i][j] = bit_min_get(&(*grid)[i - 1][j - 1], &(*grid)[i
						- 1][j], &(*grid)[i][j - 1]);
			j++;
		}
		i++;
	}
}

int	solve_init(t_data *map_data, int ***grid)
{
	g_ans_row = 0;
	g_ans_col = 0;
	g_max_size = 0;
	solve(map_data, grid);
	g_max_size = get_max_size(map_data, grid);
	print_ans(map_data, grid);
	return (0);
}