/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:47:58 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/13 21:50:44 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_lst	*new_lst(char *content)
{
	t_lst	*new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	if (!(new->str = malloc(BUFFER_SIZE + 1)))
	{
		free(new);
		return (NULL);
	}
	if (content)
		str_copy(new->str, content, '\0');
	else
		*new->str = '\0';
	new->next = NULL;
	return (new);
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
	dst[copylen] = '\0';
	return (copylen);
}

size_t	lst_size(t_lst *lst)
{
	size_t	index;
	size_t	lstsize;

	lstsize = 0;
	while (lst)
	{
		index = 0;
		while (lst->str[index] && lst->str[index] != '\n')
			index++;
		lstsize += index;
		lst = lst->next;
	}
	return (lstsize + 1);
}

int		lst_clear(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*release;

	tmp = *lst;
	while (tmp)
	{
		release = tmp;
		tmp = tmp->next;
		free(release->str);
		free(release);
	}
	*lst = NULL;
	return (-1);
}

void	fd_clear(t_fdlst **fdrmn, int fd)
{
	t_fdlst		*current;
	t_fdlst		*tmp;

	tmp = *fdrmn;
	while (tmp->fd != fd)
	{
		current = tmp;
		tmp = tmp->next;
	}
	if (tmp == *fdrmn)
		*fdrmn = tmp->next;
	else
		current->next = tmp->next;
	free(tmp->str);
	free(tmp);
}
