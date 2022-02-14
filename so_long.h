/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:10:33 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:46:15 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include	"minilibx-linux/mlx.h"
# include	<fcntl.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# define BUFFER_SIZE 32

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_models {
	t_data	*wall;
	t_data	*player;
	t_data	*exit;
	t_data	*collectible;
	t_data	*floor;
}				t_models;

typedef struct s_position {
	int		x;
	int		y;
}				t_position;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	int			mapcols;
	int			maprows;
	char		*filepath;
	int			moves_count;
	int			collectible_count;
	int			p;
	int			c;
	int			e;
	char		**buffer;
	t_models	*models;
	t_position	*player;
}				t_vars;

int			ft_length(int n);
int			is_negative(int number);
int			count_digits(unsigned int number);
char		*ft_itoa(int n);
int			map_rows(t_vars *vars);
int			map_collums(t_vars *vars);
int			create_map_helper(t_vars *vars, int i, int j, char *line);
int			create_map(t_vars *vars);
int			finish_game(t_vars *vars);
int			move_up(t_vars *vars);
int			move_down(t_vars *vars);
int			move_left(t_vars *vars);
int			move_right(t_vars *vars);
int			render_map(t_vars *vars);
int			if_wall(t_vars *vars, int x, int y);
int			if_exit(t_vars *vars, int x, int y);
int			key_hook(int keycode, t_vars *vars);
int			main(int argc, char **argv);
int			check_file_format(int argc, char **argv);
int			check_rectangular(t_vars *vars);
int			check_walls(t_vars *vars);
int			assets_check(t_vars *vars);
int			elements_check(t_vars *vars);
t_vars		*malloc_world(void);
int			create_world(t_vars *vars);
int			free_world(t_vars *vars);
int			exit_game(t_vars *vars);
void		ft_mem_del(void **line);
void		ft_mem_del_two(void **line, void **buff);
char		*get_next_line(int fd, t_vars *vars);
void		ft_bzero(void *s, size_t n);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t num, size_t size);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

#endif