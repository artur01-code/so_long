/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 02:17:37 by jtomala           #+#    #+#             */
/*   Updated: 2022/01/25 15:44:43 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)

{
	char	*src;

	src = (char *)s;
	while (*src)
	{
		if (*src == (char)c)
			return (src);
		src++;
	}
	if (!(*src) && !c)
		return (src);
	else
		return (NULL);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(size * num);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst);
	if (size == 0 || (len > size - 1))
		return (ft_strlen(src) + size);
	j = len;
	while (((len + i) < (size - 1)) && (src[i]))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	if (len >= size)
		len = size;
	return (len + ft_strlen(src));
}
