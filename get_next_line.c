/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:40:03 by jlebard           #+#    #+#             */
/*   Updated: 2024/01/10 13:18:23 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	size_t			count;
	FILE			*file;

	file = fd;
	buffer = malloc(count + 1);
	read(file, buffer, count);
	//fonction pour identifier si dans les 
	//count bytes lus il y a un \n 
}
