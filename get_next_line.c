/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:40:03 by jlebard           #+#    #+#             */
/*   Updated: 2024/01/10 15:21:39 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_advance_buffer(char	*buffer, int fd)
{
	size_t	i;
	FILE	*file;

	file = fd;
	i = 0;
	read(file, buffer, BUFFER_SIZE);
	return (buffer);
}

int	ft_check_if_end_line(char	*buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i++])
	{	
		if (buffer[i] == '\n')
			j++;
	}
	return (j);
}

char	*get_line(char	*buffer)
{
	size_t	i;

	i = ft_strlen(buffer);
	line = malloc(i + 1);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static int		count_line;
	char			*line;
	size_t			i;

	ft_advance_buffer(buffer, fd);
	i = 0;
	while (buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_get_line(buffer);
	return (line);
}
