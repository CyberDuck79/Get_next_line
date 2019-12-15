/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:55:17 by fhenrion          #+#    #+#             */
/*   Updated: 2019/12/15 17:22:50 by fhenrion         ###   ########.fr       */
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

long	next_line(char *s);
size_t	str_copy(char *dst, const char *src, char end);
char	*new_line(size_t count);
int		remain_copy(int fd, char **rmn, char *buf, char **line);
int		read_fd(int fd, char **rmn, char **line, size_t offset);
int		get_next_line(const int fd, char **line);

#endif
