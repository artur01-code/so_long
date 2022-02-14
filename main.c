/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:10:07 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:45:11 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->maprows != 0 && vars->map != NULL)
	{
		while (i < vars->maprows)
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
	}
	return (1);
}

int	free_world(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->models->wall->img);
	free(vars->models->wall);
	mlx_destroy_image(vars->mlx, vars->models->floor->img);
	free(vars->models->floor);
	mlx_destroy_image(vars->mlx, vars->models->collectible->img);
	free(vars->models->collectible);
	mlx_destroy_image(vars->mlx, vars->models->player->img);
	free(vars->models->player);
	mlx_destroy_image(vars->mlx, vars->models->exit->img);
	free(vars->models->exit);
	free(vars->player);
	free(vars->models);
	free_map(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->buffer[0]);
	free(vars->buffer);
	free(vars->mlx);
	free(vars);
	return (1);
}

int	exit_game(t_vars *vars)
{
	free_world(vars);
	exit(1);
	return (1);
}

int	check_file(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\nNo file.\n", 14);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{	
	t_vars		*vars;

	if (check_file_format(argc, argv) == 0)
		return (0);
	if (check_file(argv[1]) == 0)
		return (0);
	vars = malloc_world();
	vars->filepath = argv[1];
	create_world(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	if (create_map(vars) == 0)
	{
		free_world(vars);
		return (0);
	}
	if (check_walls(vars) == 0 || assets_check(vars) == 0
		|| elements_check(vars) == 0)
	{
		free_world(vars);
		return (0);
	}
	render_map(vars);
}
