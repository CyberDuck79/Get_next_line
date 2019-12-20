/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 00:15:27 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/16 13:22:31 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct		s_lst
{
	char			*str;
	struct s_lst	*next;
}					t_lst;

t_lst				*new_lst(char **content);
size_t				str_copy(char *dst, const char *src, char end);
size_t				lst_size(t_lst *lst);
int					lst_clear(t_lst **lst);
int					get_next_line(const int fd, char **line);

#endif
