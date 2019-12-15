/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:37:22 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/15 18:18:22 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	next_line(char *s)
{
	long	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

size_t	str_copy(char *dst, const char *src, char end)
{
	size_t	copylen;

	copylen = 0;
	while (src[copylen] != end)
	{
		dst[copylen] = src[copylen];
		copylen++;
	}
	return (copylen);
}

char	*new_line(size_t count)
{
	char	*new;

	if (!(new = malloc(count + 1)))
		return (NULL);
	new[count] = '\0';
	return (new);
}
