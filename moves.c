/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:10:24 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:45:50 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player->x;
	y = vars->player->y;
	if (if_wall(vars, x, y - 1) == 1 || if_exit(vars, x, y - 1) == 1)
		return (0);
	if (vars->map[y - 1][x] == 'C')
		vars->collectible_count--;
	if (vars->map[y - 1][x] == 'E' && vars->collectible_count == 0)
		exit_game(vars);
	vars->map[y][x] = '0';
	vars->map[y - 1][x] = 'P';
	vars->player->y = y - 1;
	vars->moves_count++;
	return (1);
}

int	move_down(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player->x;
	y = vars->player->y;
	if (if_wall(vars, x, y + 1) == 1 || if_exit(vars, x, y + 1) == 1)
		return (0);
	if (vars->map[y + 1][x] == 'C')
		vars->collectible_count--;
	if (vars->map[y + 1][x] == 'E' && vars->collectible_count == 0)
		exit_game(vars);
	vars->map[y][x] = '0';
	vars->map[y + 1][x] = 'P';
	vars->player->y = y + 1;
	vars->moves_count++;
	return (1);
}

int	move_left(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player->x;
	y = vars->player->y;
	if (if_wall(vars, x - 1, y) == 1 || if_exit(vars, x - 1, y) == 1)
		return (0);
	if (vars->map[y][x - 1] == 'C')
		vars->collectible_count--;
	if (vars->map[y][x - 1] == 'E' && vars->collectible_count == 0)
		exit_game(vars);
	vars->map[y][x] = '0';
	vars->map[y][x - 1] = 'P';
	vars->player->x = x - 1;
	vars->moves_count++;
	return (1);
}

int	move_right(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player->x;
	y = vars->player->y;
	if (if_wall(vars, x + 1, y) == 1 || if_exit(vars, x + 1, y) == 1)
		return (0);
	if (vars->map[y][x + 1] == 'C')
		vars->collectible_count--;
	if (vars->map[y][x + 1] == 'E' && vars->collectible_count == 0)
		exit_game(vars);
	vars->map[y][x] = '0';
	vars->map[y][x + 1] = 'P';
	vars->player->x = x + 1;
	vars->moves_count++;
	return (1);
}
