/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:13:06 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/19 10:39:45 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	next_line(const char *s)
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

size_t	str_copy(char *dst, const char *src, char end, int close)
{
	size_t	copylen;

	copylen = 0;
	while (src[copylen] != end)
	{
		dst[copylen] = src[copylen];
		copylen++;
	}
	if (close)
		dst[copylen] = '\0';
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