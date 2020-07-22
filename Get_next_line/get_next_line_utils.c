/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:31:35 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/21 11:28:56 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while(s[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	char			*s1;
	unsigned char	c2;

	s1 = (char *)s;
	c2 = c;
	while (*s1 != '\0')
	{
		if (*s1 == c2)
			return (s1);
		s1++;
	}
	if (*s1 == '\0' && c2 == '\0')
		return (s1);
	return (NULL);
}