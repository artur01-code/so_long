/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:10:16 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:45:25 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_format(int argc, char **argv)
{
	int		i;
	char	*name;

	i = 0;
	if (argc < 2)
	{
		write(1, "Error\nWrong number of arguments.\n", 33);
		return (0);
	}
	name = argv[1];
	while (name[i] != '.')
	{
		if (name[i++] == '\0')
		{
			write(1, "Error\nNo map.\n", 14);
			return (0);
		}
	}
	if (name[i + 1] != 'b' || name[i + 2] != 'e' || name[i + 3] != 'r'
		|| name[i + 4] != '\0')
	{
		write(1, "Error\nWrong map format.\n", 24);
		return (0);
	}
	return (1);
}

int	check_walls(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->mapcols)
	{
		if (vars->map[0][i] != '1' || vars->map[vars->maprows - 1][i] != '1')
		{
			write(1, "Error\nMap not surrounded by walls.\n", 35);
			return (0);
		}
		i++;
	}
	while (j < vars->maprows)
	{
		if (vars->map[j][0] != '1' || vars->map[j][vars->mapcols - 1] != '1')
		{
			write(1, "Error\nMap not surrounded by walls.\n", 35);
			return (0);
		}
		j++;
	}
	return (1);
}

int	assets_count(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->maprows)
	{
		while (j < vars->mapcols)
		{
			if (vars->map[i][j] == 'P')
				vars->p++;
			if (vars->map[i][j] == 'E')
				vars->e++;
			if (vars->map[i][j] == 'C')
				vars->c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	assets_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	assets_count(vars);
	while (i < vars->maprows)
	{
		while (j < vars->mapcols)
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != '\n'
			&& vars->map[i][j] != 'C' && vars->map[i][j] != '0'
			&& vars->map[i][j] != 'E' && vars->map[i][j] != 'P')
			{
				write(1, "Error\nUnidentified character.\n", 30);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	elements_check(t_vars *vars)
{
	vars->collectible_count = vars->c;
	if (vars->e > 1 || vars->p > 1)
	{
		write(1, "Error\nToo many elements.\n", 25);
		return (0);
	}
	if (vars->e == 0 || vars->p == 0 || vars->c == 0)
	{
		write(1, "Error\nNot enough content.\n", 26);
		return (0);
	}
	return (1);
}
