/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:12:01 by jlebard           #+#    #+#             */
/*   Updated: 2024/04/02 13:22:22 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest1 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest1)
		return (NULL);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		dest1[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest1[i + j] = s2[j];
		j++;
	}
	dest1[i + j] = '\0';
	return (dest1);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	temp;

	ptr = s;
	temp = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = temp;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*dest;

	if (n == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / n < size)
		return (NULL);
	dest = malloc(n * size);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, n * size);
	return (dest);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char	*s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
