/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 14:25:56 by aheister      #+#    #+#                 */
/*   Updated: 2021/02/02 08:03:57 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 30

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_nl(char *str);
char	*ft_realloc(char *left, int len);
char	*fill_join(char *left, char *buf, char *str_join);
char	*ft_strjoin(char *left, char *buf);
char	*fill_str(char *str, int start, int type);
char	*fill_left(char *left, char *buf);
char	*fill_buf(int fd);
int		get_line(int fd, char **line);
int		get_next_line(int fd, char **line);

#endif
