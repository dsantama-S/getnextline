/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:31:32 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/23 12:49:31 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			return_vl(int fd, char *ln, char **line)
{
	while (ln[fd] != '\0')
	{
		return (1);
		get_next_line(fd, line);
	}
	return (0);
}

static int			error_reading(int reading, char **line)
{
	if (reading < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*ln[5000];
	char			*buffer;
	int				reading;

	reading = 0;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while ((reading = read(fd, buffer, BUFFER_SIZE)) && reading > 0)
	{
		buffer[reading] = '\0';
		if (!ln[fd])
			ln[fd] = ft_strdup(buffer);
		else
			ln[fd] = ft_strjoin(ln[fd], buffer);
		if (ft_strchr(ln[fd], '\n'))
			break ;
	}
	free(buffer);
	if (reading < 0 || (reading == 0 && !ln[fd]))
		return (error_reading(reading, line));
	return (return_vl(fd, ln[fd], line));
}
