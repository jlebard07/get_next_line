/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:40:03 by jlebard           #+#    #+#             */
/*   Updated: 2024/02/01 10:14:06 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *dest, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(dest, buffer);
	free(dest);
	return (temp);
}

char	*ft_read(int fd, char *dest)
{
	char	*temp;
	int		i;

	if (!dest)
		dest = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[i] = '\0';
		dest = ft_free(dest, temp);
		if (ft_strchr(temp, 10) != NULL)
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
	while (buffer[i] && buffer[i] != '\n')
		i++;
	dest = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buffer[i] && buffer [i] != '\n')
	{
		dest[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		dest[i] = 10;
		i++;
	}
	return (dest);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	dest = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	while (buffer[i])
		dest[j++] = buffer[i++];
	dest[j] = '\0';
	free(buffer);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
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

// 	line = ft_calloc(1, 1);
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 		return (1);
// 	}
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	close (fd);
// 	return (0);
// }
