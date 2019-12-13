/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 00:16:38 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/13 21:50:45 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*next_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

static t_fdlst	*get_remain(t_fdlst **fdrmn, int fd)
{
	t_fdlst		*tmp;

	tmp = *fdrmn;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = malloc(sizeof(t_fdlst))))
		return (NULL);
	if (!(tmp->str = malloc(BUFFER_SIZE + 1)))
	{
		free(tmp);
		return (NULL);
	}
	tmp->fd = fd;
	*tmp->str = '\0';
	tmp->next = *fdrmn;
	*fdrmn = tmp;
	return (tmp);
}

static char		*get_line(t_lst *buflst, const char *next)
{
	size_t	index;
	char	*line;

	if (buflst->str)
	{
		if (!(line = malloc(lst_size(buflst))))
			return (NULL);
		index = 0;
		while (buflst->next)
		{
			index += str_copy(line + index, buflst->str, '\0');
			buflst = buflst->next;
		}
		str_copy(line + index, buflst->str, next ? '\n' : '\0');
		return (line);
	}
	if (!(line = malloc(1)))
		return (NULL);
	*line = '\0';
	return (line);
}

int				read_fd(int fd, char **next, t_lst **buflst)
{
	char		buf[BUFFER_SIZE + 1];
	size_t		count;

	if (!*buflst)
		*buflst = new_lst(NULL);
	if (!*(*buflst)->str)
	{
		if (read(fd, buf, 0) < 0)
			return (-1);
		if (!(count = read(fd, buf, BUFFER_SIZE)))
			return (0);
		buf[count] = '\0';
		str_copy((*buflst)->str, buf, '\0');
		if ((*next = next_line((*buflst)->str)))
			return (0);
	}
	return (read_fd(fd, next, &(*buflst)->next));
}

int				get_next_line(const int fd, char **line)
{
	static t_fdlst	*fdrmn;
	t_fdlst			*rmn;
	t_lst			*buflst;
	char			*next;

	rmn = get_remain(&fdrmn, fd);
	buflst = new_lst(rmn->str);
	if (fd < 0 || !line || !BUFFER_SIZE || !buflst)
		return (lst_clear(&buflst));
	if (!(next = next_line(buflst->str)))
		if (read_fd(fd, &next, &buflst))
			return (lst_clear(&buflst));
	*line = get_line(buflst, next);
	if (next)
		str_copy(rmn->str, next + 1, '\0');
	else
		fd_clear(&fdrmn, fd);
	lst_clear(&buflst);
	return (next ? 1 : 0);
}
