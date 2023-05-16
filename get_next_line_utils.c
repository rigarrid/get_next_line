/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:40:49 by rigarrid          #+#    #+#             */
/*   Updated: 2023/05/11 16:19:58 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(char const *s, int c)
{
	while (*s && *s != (unsigned char)c)
		++s;
	if (*s == (unsigned char)c)
		return ((char *)(unsigned long)s);
	else
		return (0);
}

size_t	ft_strlen(char const *str)
{
	size_t	con;

	con = 0;
	while (str[con])
		con++;
	return (con);
}

char	*ft_strdup(char const *str)
{
	char	*dup;
	char	*ptr;

	dup = malloc (sizeof (*dup) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (dup);
}

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*result;
	int		c;
	int		c2;

	if (!s1)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	c = -1;
	c2 = 0;
	while (s1[++c])
	{
		result[c2] = s1[c];
		c2++;
	}
	c = -1;
	while (s2[++c])
	{
		result[c2] = s2[c];
		c2++;
	}
	result[c2] = 0;
	free(s1);
	return (result);
}

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	len = ft_strlen (str);
	if (start >= len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	sub = malloc (sizeof (*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}