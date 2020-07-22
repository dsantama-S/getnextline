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

int			get_next_line(int fd, char **line)
{	
	char	*buffer;
	int		reading;
	int		c;
	
	c = 0;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (line[c] != '\0')
	{
		buffer = *line;
		c++;
	}
	reading = read(fd, buffer, BUFFER_SIZE);
	if (reading == 1)
		return (1);
	if (reading != 1)
		return (-1);
	return (0);
}
