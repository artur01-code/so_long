/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:09:41 by jtomala          #+#    #+#             */
/*   Updated: 2022/01/25 15:44:16 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* reads number of rows from the text file by counting nr of lines*/
int	map_rows(t_vars *vars)
{
	int		fd;
	int		nr_lines;
	char	*nl;

	fd = open(vars->filepath, O_RDONLY);
	nr_lines = 0;
	nl = get_next_line(fd, vars);
	while (nl != NULL)
	{
		free(nl);
		nr_lines++;
		nl = get_next_line(fd, vars);
	}
	close(fd);
	free(nl);
	return (nr_lines);
}

/* reads number of collums from the text file by reading strlen of first coll
returns 0 if every new read line is not equal to the first*/
int	map_collums(t_vars *vars)
{
	int		nr_collums;
	char	*nl;
	char	size;
	int		fd;

	fd = open(vars->filepath, O_RDONLY);
	nl = get_next_line(fd, vars);
	size = ft_strlen(nl);
	while (nl != NULL)
	{
		nr_collums = ft_strlen(nl);
		if (size != nr_collums)
		{
			write(1, "Error\nMap not rectangular.\n", 27);
			close(fd);
			free(nl);
			return (0);
		}
		free(nl);
		nl = get_next_line(fd, vars);
	}
	close(fd);
	free(nl);
	return (nr_collums);
}

/*mallocs space for the map based on size of rows x collums and assigns 
player coordinates to be used later with keyhooks*/
int	malloc_map(t_vars *vars)
{
	int		i;

	i = 0;
	vars->mapcols = map_collums(vars);
	if (vars->mapcols == 0)
		return (0);
	vars->maprows = map_rows(vars);
	vars->map = malloc(vars->maprows * sizeof(char *));
	while (i < vars->maprows)
	{
		vars->map[i] = malloc(vars->mapcols * sizeof(char *));
		i++;
	}
	return (1);
}

/*populates the map with the content of the text file
sets player position*/

int	create_map_helper(t_vars *vars, int i, int j, char *line)
{
	while (j < vars->mapcols && line != NULL)
	{
		vars->map[i][j] = line[j];
		if (vars->map[i][j] == 'P')
		{
			vars->player->x = j;
			vars->player->y = i;
		}
		j++;
	}
	return (1);
}

int	create_map(t_vars *vars)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = 0;
	j = 0;
	if (malloc_map(vars) == 0)
		return (0);
	fd = open(vars->filepath, O_RDONLY);
	while (i < vars->maprows)
	{
		line = get_next_line(fd, vars);
		create_map_helper(vars, i, j, line);
		free(line);
		j = 0;
		i++;
	}
	close(fd);
	return (1);
}
