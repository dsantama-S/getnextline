/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:31:32 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/21 11:41:11 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			return_vl(int fd, int reading,	char *ln, char **line)
{
	while(ln[fd] != '\0')
	{
		return (1);
		get_next_line(fd, line);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*ln;
	char			*buffer;
	int				reading;
	char			c;


	reading = 0;
	c = '\n';
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	reading = read(fd, buffer, BUFFER_SIZE);
	if (reading < 0)
			return (-1);
	while (reading >= 0)
	{
		if (reading == 0)
			return (0);
		if (ft_strchr(ln[fd], c))
		{
			ln = ft_strchr(ln[fd], c);
			break;
		}
	}
	buffer[reading] = '\0';
	free(buffer);
	return (return_vl(fd, reading, ln, line));
}
