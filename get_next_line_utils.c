/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:40:49 by rigarrid          #+#    #+#             */
/*   Updated: 2023/05/17 14:54:14 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*
 * Searches for the first occurrence of a character C in the string S. 
 * It returns a pointer to the located character or NULL if the character 
 * is not found. It uses a while loop to iterate through each character 
 * of the string until it finds the desired character.
 */

char	*ft_strchr(char const *s, int c)
{
	while (*s && *s != (unsigned char)c)
		++s;
	if (*s == (unsigned char)c)
		return ((char *)(unsigned long)s);
	else
		return (0);
}

/*
 * Calculates the length of a string STR by counting the number of characters 
 * until it reaches the null terminator ('\0'). It returns the length as 
 * a size_t value.
*/

size_t	ft_strlen(char const *str)
{
	size_t	con;

	con = 0;
	while (str[con])
		con++;
	return (con);
}

/*
 * Creates a duplicate of the input string STR. It allocates memory 
 * for the duplicate string, copies the characters from the original string 
 * to the duplicate, and returns a pointer to the duplicate string.
*/

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

/*
 * Concatenates two strings S1 and S2 into a new string. It first allocates 
 * memory to hold the concatenated string by calculating the combined length 
 * of S1 and S2, then copies the characters from S1 and S2 to the new string. 
 * It also frees the memory allocated for S1 and returns the new concatenated 
 * string.
*/

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

/*
 * Extracts a substring from a string STR starting at index START 
 * and with a maximum size of SIZE. It allocates memory for the substring, 
 * copies the characters from the original string to the substring, 
 * and returns a pointer to the substring. If START is greater than or equal 
 * to the length of the string, it returns an empty string.
 */

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
