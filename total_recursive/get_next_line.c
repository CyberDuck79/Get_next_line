/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:55:38 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/16 00:32:49 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static long		next_line(char *s)
{
	long		index;

	index = 0;
	while (s[index])
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

static size_t	str_copy(char *dst, const char *src, char end)
{
	size_t		copylen;

	copylen = 0;
	while (src[copylen] != end)
	{
		dst[copylen] = src[copylen];
		copylen++;
	}
	return (copylen);
}

static char		*new_line(size_t count)
{
	char		*new;

	if (!(new = malloc(count + 1)))
		return (NULL);
	new[count] = '\0';
	return (new);
}


static int		read_fd(const int fd, char **rmn, char **line, size_t offset)
{
	char		buf[BUFFER_SIZE + 1];
	long		n;
	size_t		count;
	int			ret;

	if (read(fd, buf, 0) < 0)
		return (-1);
	if ((count = str_copy(buf, *rmn, '\0')))
		**rmn = 0;
	else if (!(count = read(fd, buf, BUFFER_SIZE)))
		return ((*line = new_line(offset)) ? 0 : -1);
	buf[count] = '\0';
	if ((n = next_line(buf)) >= 0)
	{
		str_copy(*rmn, buf + n + 1, '\0');
		(*rmn)[count - n - 1] = '\0';
		if ((*line = new_line(offset + n)))
			str_copy(*line + offset, buf, '\n');
		return (*line ? 1 : -1);
	}
	if ((ret = read_fd(fd, rmn, line, offset + count)) == -1)
		return (-1);
	str_copy(*line + offset, buf, '\0');
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rmn;
	int			ret;

	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	if (!rmn)
	{
		if (!(rmn = malloc(BUFFER_SIZE + 1)))
			return (-1);
		*rmn = 0;
	}
	if ((ret = read_fd(fd, &rmn, line, 0)) < 1)
	{
		free(rmn);
		rmn = NULL;
	}
	return (ret);
}