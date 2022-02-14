/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:06:19 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:44:09 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*creates map in accordance to the given values in the text file, each value 
corresponding to their image
each model taxes 100 x 100 pixels
*/

int	render_map_image(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->models->wall->img, j * 100, i * 100);
	else if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->models->floor->img, j * 100, i * 100);
	else if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->models->player->img, j * 100, i * 100);
	else if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->models->collectible->img, j * 100, i * 100);
	else if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->models->exit->img, j * 100, i * 100);
	return (1);
}

int	render_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_hook(vars->win, 33, (1L << 17), exit_game, vars);
	while (i < vars->maprows)
	{
		while (j < vars->mapcols)
		{
			render_map_image(vars, i, j);
		j++;
		}
	j = 0;
	i++;
	}
	mlx_loop(vars->mlx);
	return (1);
}

/* key hooks respresenting the W S A D movements on the keyboard as well
 as their corresponding actions*/

int	print_hook(t_vars *vars)
{
	char	*i;
	int		len;

	i = ft_itoa(vars->moves_count);
	len = ft_strlen(i);
	write(1, i, len);
	write(1, "\n", 1);
	free(i);
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119)
	{
		if (move_up(vars) == 1)
			print_hook(vars);
	}
	else if (keycode == 115)
	{
		if (move_down(vars) == 1)
			print_hook(vars);
	}
	else if (keycode == 97)
	{
		if (move_left(vars) == 1)
			print_hook(vars);
	}
	else if (keycode == 100)
	{
		if (move_right(vars) == 1)
			print_hook(vars);
	}
	else if (keycode == 65307)
		exit(1);
	render_map(vars);
	return (0);
}
