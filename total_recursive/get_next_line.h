/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:55:17 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/19 10:52:36 by fhenrion         ###   ########.fr       */
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


size_t	rmn_restore(char *dst, char *src);
char	*new_line(size_t count);
int 	next_line_index(const char *s);
void	rmn_save(char *dst, const char *src);
void	buf_copy(char *dst, const char *src, char end);
int		get_next_line(const int fd, char **line);

#endif
