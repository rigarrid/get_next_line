/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:36:05 by rigarrid          #+#    #+#             */
/*   Updated: 2023/05/11 16:32:47 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_next(char **tmp)
{
	char	*line;
	char	*ptr;

	ptr = *tmp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr (*tmp, 0, (size_t)(ptr - *tmp));
	if (!line)
	{
		free (*tmp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr));
	free (*tmp);
	*tmp = ptr;
	return (line);
}

static char	*ft_read(char *tmp, int fd, char *buffer)
{
	ssize_t		br;

	br = 1;
	while (br && !ft_strchr (tmp, '\n'))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br == -1)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		buffer[br] = 0;
		tmp = ft_strjoinfree(tmp, buffer);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		*buffer;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	if (!tmp[fd])
		return (NULL);
	buffer = malloc (sizeof (*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (tmp[fd]);
		return (NULL);
	}
	tmp[fd] = ft_read (tmp[fd], fd, buffer);
	if (!tmp[fd])
		return (NULL);
	if (!*tmp[fd])
	{
		free (tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&tmp[fd]));
}

/*int main()
{
int fd = open("prueba.txt", O_RDONLY);
	// Utilizar o imprimir cada línea leída
	printf("%s", get_next_line(fd));

	close(fd);
	return 0;
}*/