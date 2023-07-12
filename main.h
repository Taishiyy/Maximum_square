#ifndef MAIN_H
# define MAIN_H
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int			filesize;
	int			row;
	int			col;
	char		empty;
	char		obstacle;
	char		full;
}				t_data;

int				start(char *filename);
unsigned int	get_filesize(char *map_name);
int				adv_prep(t_data *map_data, int file_size, char *filename,
					int ***grid);
int				get_map(char *buffer, t_data *map_data, int ***grid);
int				solve_init(t_data *map_data, int ***grid);
void			solve(t_data *map_data, int ***grid);
int				get_max_size(t_data *map_data, int ***grid);
void			print_ans(t_data *map_data, int ***grid);
int				bit_min_get(int *ul, int *u, int *l);
void			ft_free(int ***grid);
bool			open_check(int fd, char *buffer);
bool			read_check(int fd, int rd, char *buffer);
bool			firstline_check(char *buffer, t_data *map_data, int *index);
bool			firstline_set(char emp, char obs, char ful, t_data *map_data);
bool			second_line_check(char *buffer, t_data *map_data, int *index);
bool			line_count(char *buffer, t_data *map_data, int *index);
bool			map_symbol_check(char *buffer, t_data *map_data, int index);
bool			check_all_error(int fd, int rd, char *buffer, t_data *map_data);
bool			check_loop(char *buffer, t_data *map_data, int *index);

#endif