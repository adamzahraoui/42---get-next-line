/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:15:00 by adzahrao          #+#    #+#             */
/*   Updated: 2024/11/26 05:17:30 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*chyata(char *last)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!last)
		return (NULL);
	i = 0;
	while (last[i] != '\0' && last[i] != '\n')
		i++;
	if (last[i] == '\n')
		i++;
	if (last[i] == '\0')
		return (free(last), NULL);
	p = malloc(ft_strlen(last) - i + 1);
	if (!p)
		return (free(last), NULL);
	j = 0;
	while (last[i])
		p[j++] = last[i++];
	p[j] = '\0';
	free(last);
	return (p);
}

char	*line_buffer(int fd, char *last)
{
	char	*buffer;
	char	*temp;
	ssize_t	len;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(last), NULL);
	len = 1;
	while (!ft_strchr(last, '\n') && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (free(buffer), free(last), NULL);
		buffer[len] = '\0';
		temp = ft_strjoin(last, buffer);
		free(last);
		if (!temp)
			return (free(buffer), NULL);
		last = temp;
	}
	free(buffer);
	return (last);
}

char	*line_n9i(char *last)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!last)
		return (NULL);
	i = 0;
	while (last[i] != '\0' && last[i] != '\n')
		i++;
	if (last[i] == '\n')
		i++;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = last[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!last)
	{
		last = malloc(1);
		if (!last)
			return (NULL);
		last[0] = '\0';
	}
	last = line_buffer(fd, last);
	if (!last)
		return (NULL);
	if (!*last)
		return ((free(last), last = NULL), NULL);
	line = line_n9i(last);
	if (!line)
		return ((free(last), last = NULL), NULL);
	last = chyata(last);
	return (line);
}
