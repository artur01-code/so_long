/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:25:16 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:46:03 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_length(int n)
{
	int		y;

	y = 0;
	if (n <= 0)
		y++;
	while (n)
	{
		n = n / 10;
		y++;
	}
	return (y);
}

int	is_negative(int number)
{
	if (number < 0)
		return (1);
	else
		return (0);
}

int	count_digits(unsigned int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number >= 1)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	negative;
	unsigned int	number;
	unsigned int	digits;

	negative = is_negative(n);
	if (negative == 1)
		number = -n;
	else
		number = n;
	digits = count_digits(number);
	str = (char *)malloc(digits + negative + 1);
	if (str == NULL)
		return (NULL);
	if (negative == 1)
		str[0] = '-';
	str[digits + negative] = '\0';
	while (digits > 0)
	{
		str[(digits - 1) + negative] = (number % 10) + '0';
		number /= 10;
		digits--;
	}
	return (str);
}

void	ft_mem_del_two(void **line, void **buff)

{
	if (line != NULL)
	{
		free(*line);
		free(*buff);
		*line = NULL;
		*buff = NULL;
	}
}
