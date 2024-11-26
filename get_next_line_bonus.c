/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:31:55 by adzahrao          #+#    #+#             */
/*   Updated: 2024/11/26 05:16:44 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*last[MAX_FDS];
	char		*line;

	if (fd < 0 || fd >= MAX_FDS || BUFFER_SIZE <= 0)
		return (NULL);
	if (!last[fd])
	{
		last[fd] = malloc(1);
		if (!last[fd])
			return (NULL);
		last[fd][0] = '\0';
	}
	last[fd] = line_buffer(fd, last[fd]);
	if (!last[fd])
		return (NULL);
	if (!*last[fd])
		return ((free(last[fd]), last[fd] = NULL), NULL);
	line = line_n9i(last[fd]);
	if (!line)
		return ((free(last[fd]), last[fd] = NULL), NULL);
	last[fd] = chyata(last[fd]);
	return (line);
}
