/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:44:07 by rigarrid          #+#    #+#             */
/*   Updated: 2023/04/17 11:44:17 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prueba.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	con;
	char	*aux;

	con = 0;
	aux = s;
	while (con < n)
	{
		aux[con] = 0;
		con++;
	}
}

static int	ft_putstr(char *str)
{
	int	size;

	size = 0;
	if (str == NULL)
		size = ft_putstr("(null)");
	else
		while (str[size])
			write(1, &str[size++], 1);
	return (size);
}

static size_t	ft_strlen(const char *s)
{
	size_t	con;

	con = 0;
	while (s[con])
		con++;
	return (con);
}

static size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	dlen;
	size_t	d;
	size_t	slen;

	dlen = ft_strlen(dest);
	slen = ft_strlen((char *)src);
	d = 0;
	if (nb == 0)
		return (slen);
	if (dlen > nb)
		return (slen + nb);
	while (((unsigned char *) src)[d] && dlen < (nb - 1))
	{
		dest[dlen] = ((unsigned char *) src)[d];
		dlen++;
		d++;
	}
	if (d < nb)
		dest[dlen] = 0;
	return ((dlen - d) + slen);
}

char *get_next_line(int fd)
{
	char	*buffer;
	char	*end;
	int		flow;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	end = (char *)malloc((BUFFER_SIZE * 2));
	if (end == NULL)
		return (NULL);
	ft_bzero(end, (BUFFER_SIZE * 2));
	ft_bzero(buffer, (BUFFER_SIZE + 1));
	flow = read(fd, buffer, BUFFER_SIZE);
	if (flow > 0 )
	{
		ft_strlcat(end, buffer, BUFFER_SIZE);
	}
	else if (flow <= 0)
		free(buffer);
	return (end);
}

int main()
{
	int		fd;
	char	*all;

	fd = open("prueba.txt", O_RDONLY);
	all = get_next_line(fd);
	ft_putstr(all);
	all = get_next_line(fd);
	ft_putstr(all);
	
	return (0);
}