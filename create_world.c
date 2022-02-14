/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:53:21 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/27 15:02:42 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* initializes the world on given parameters 1920 x 1080
assings each struct to their given files
*/

t_vars	*malloc_world(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->buffer = ft_calloc(1, sizeof(char *));
	vars->buffer[0] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	vars->models = (t_models *)malloc(sizeof(t_models));
	vars->models->wall = (t_data *)malloc(sizeof(t_data));
	vars->models->floor = (t_data *)malloc(sizeof(t_data));
	vars->models->collectible = (t_data *)malloc(sizeof(t_data));
	vars->models->player = (t_data *)malloc(sizeof(t_data));
	vars->models->exit = (t_data *)malloc(sizeof(t_data));
	vars->player = (t_position *)malloc(sizeof(t_position));
	return (vars);
}

int	create_world(t_vars *vars)
{
	int			img_width;
	int			img_height;

	vars->maprows = 0;
	vars->moves_count = 0;
	vars->p = 0;
	vars->e = 0;
	vars->c = 0;
	img_width = 100;
	img_height = 100;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1980, 1020, "So long!");
	vars->models->wall->img = mlx_xpm_file_to_image(vars->mlx, \
		"img/wall.xpm", &img_width, &img_height);
	vars->models->floor->img = mlx_xpm_file_to_image(vars->mlx, \
		"img/ground.xpm", &img_width, &img_height);
	vars->models->collectible->img = mlx_xpm_file_to_image(vars->mlx, \
		"img/rice.xpm", &img_width, &img_height);
	vars->models->player->img = mlx_xpm_file_to_image(vars->mlx, \
		"img/player.xpm", &img_width, &img_height);
	vars->models->exit->img = mlx_xpm_file_to_image(vars->mlx, \
		"img/tombstone.xpm", &img_width, &img_height);
	return (1);
}
