/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsantama <dsantama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:31:35 by dsantama          #+#    #+#             */
/*   Updated: 2020/07/30 08:29:05 by dsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char			*ft_strchr(char *s, int c)
{
	char			*s1;
	unsigned char	c2;

	s1 = s;
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

char			*ft_strdup(char *src)
{
	char				*dest;
	int					size;
	size_t				n;
	unsigned char		*s1;
	const unsigned char	*s2;

	size = ft_strlen(src);
	dest = (char *)malloc(size + 1);
	if (!dest)
		return (NULL);
	if (!src)
		return (NULL);
	n = size + 1;
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	while (n-- > 0)
		*(s1++) = *(s2++);
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	n;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[n] = *s1;
		n++;
		s1++;
	}
	while (*s2)
	{
		str[n] = *s2;
		n++;
		s2++;
	}
	str[n] = '\0';
	return (str);
}

size_t			ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	length_src;
	int		i;

	if (!dest || !src)
		return (0);
	length_src = ft_strlen(src);
	if (n != 0)
	{
		i = -1;
		if (length_src + 1 < n)
		{
			while (++i < (int)length_src)
				dest[i] = src[i];
		}
		else
		{
			while (++i < (int)n - 1)
				dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	return (length_src);
}
