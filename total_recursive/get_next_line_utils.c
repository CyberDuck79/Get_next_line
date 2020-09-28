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

size_t	rmn_restore(char *dst, char *src)
{
	size_t	copylen;

	copylen = 0;
	while (src[copylen])
	{
		dst[copylen] = src[copylen];
		copylen++;
	}
	*src = '\0';
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

int		next_line_index(const char *s)
{
	int	index;

	index = 0;
	while (s[index] && s[index] != '\n')
		index++;
	return (s[index] == '\n' ? index : -1);
}

void	rmn_save(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

void	buf_copy(char *dst, const char *src, char end)
{
	while (*src != end)
		*dst++ = *src++;
}
