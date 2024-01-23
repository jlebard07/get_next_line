/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:40:03 by jlebard           #+#    #+#             */
/*   Updated: 2024/01/23 11:45:21 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *temp, char *dest)
{
	char	*tempfree;

	tempfree = ft_strjoin(dest, temp);
	free(temp);
	return (tempfree);
}

char	*ft_read(int fd, char *dest)
{
	char	*temp;
	ssize_t	i;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[i] = '\0';
		dest = ft_free(temp, dest);
		if (ft_strchr(temp, 10))
			break ;
	}
	free(temp);
	return (dest);
}

char	*ft_get_line(char *buffer)
{
	char	*dest;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer [i] != '\n')
		i++;
	dest = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer [i] != '\n')
	{
		dest[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		dest[i + 1] = '\n';
	return (dest);
}

char	*ft_next(char *buffer)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	dest = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		dest[j++] = buffer[i++];
	free(buffer);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (line != NULL)
// 		line = get_next_line(fd);
// 	write (1, line, BUFFER_SIZE);
// 	close ("test.txt");
// 	free(line);
// 	return (0);
// }
