/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:42 by adzahrao          #+#    #+#             */
/*   Updated: 2024/11/26 05:17:14 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	d;
	size_t	i;

	p = (char *)s;
	d = (char)c;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == d)
			return (&p[i]);
		i++;
	}
	if (d == '\0')
		return (&p[i]);
	return (NULL);
}

char	*ft_strjoin(const char *dest, const char *src)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (NULL);
	i = 0;
	j = 0;
	p = malloc(ft_strlen((char *)dest) + ft_strlen((char *)src) + 1);
	if (!p)
		return (NULL);
	while (dest[i] != '\0')
	{
		p[i] = dest[i];
		i++;
	}
	while (src[j] != '\0')
	{
		p[i + j] = src[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}
