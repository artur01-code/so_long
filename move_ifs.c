/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ifs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:24:33 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:45:38 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	if_wall(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		return (1);
	else
		return (0);
}

int	if_exit(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'E' && vars->collectible_count != 0)
		return (1);
	else
		return (0);
}
