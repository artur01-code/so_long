/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 02:18:51 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:45:01 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mem_del(void **line)

{
	if (line != NULL)
	{
		free(*line);
		*line = NULL;
	}
}

int	check_for_nl(char *buffer, int buffer_len)

{
	int		i;

	if (ft_strchr(buffer, '\n'))
	{
		i = 0;
		buffer_len++;
		while (buffer[buffer_len + i] != '\0')
		{
			buffer[i] = buffer[buffer_len + i];
			i++;
		}
		ft_bzero((buffer + i), buffer_len + 1);
		return (1);
	}
	return (0);
}

int	ft_copy_content(char **line, char *buffer)

{
	int		line_len;
	char	*temp;
	int		buffer_len;

	buffer_len = ft_strlen(buffer);
	line_len = ft_strlen(*line) + buffer_len;
	temp = ft_calloc(line_len + 2, sizeof(char));
	if (!temp)
		return (-1);
	ft_strlcat(temp, *line, line_len + 2);
	ft_strlcat(temp, buffer, line_len + 2);
	ft_mem_del((void **)line);
	*line = temp;
	if (check_for_nl(buffer, buffer_len))
		return (1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	return (2);
}

int	precheck(char **line, char **buffer, int fd)

{
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0)
		return (0);
	if (!buffer[0])
		buffer[0] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	*line = ft_calloc(1, sizeof(char));
	if (!buffer || !*line)
	{
		ft_mem_del((void **)line);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd, t_vars *vars)

{
	char		*line[1];
	int			status;
	char		**buff;

	buff = vars->buffer;
	if (!precheck(line, buff, fd))
		return (0);
	while (1)
	{
		if (*buff[0] == 0)
		{
			status = read(fd, buff[0], BUFFER_SIZE);
			if (status <= 0)
				break ;
		}
		status = ft_copy_content(line, buff[0]);
		if (status < 2)
			break ;
	}
	if ((ft_strlen(*line) == 0 && status == 0) || status < 0)
	{			
		ft_mem_del_two((void **)line, (void **)buff);
		return (NULL);
	}
	return (line[0]);
}
