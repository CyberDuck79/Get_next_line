/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:55:38 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/19 11:15:15 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_fd(const int fd, char **rmn, char **line, size_t offset)
{
	char		buf[BUFFER_SIZE + 1];
	long		next;
	size_t		count;

	if (read(fd, buf, 0) < 0)
		return (-1);
	if ((count = str_copy(buf, *rmn, '\0', 0)))
		**rmn = 0;
	else if (!(count = read(fd, buf, BUFFER_SIZE)))
		return ((*line = new_line(offset)) ? 0 : -1);
	buf[count] = '\0';
	if ((next = next_line(buf)) >= 0)
	{
		str_copy(*rmn, buf + next + 1, '\0', 1);
		if ((*line = new_line(offset + next)))
			str_copy(*line + offset, buf, '\n', 0);
		return (*line ? 1 : -1);
	}
	if ((next = read_fd(fd, rmn, line, offset + count)) == -1)
		return (-1);
	str_copy(*line + offset, buf, '\0', 0);
	return (next);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rmn;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
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
