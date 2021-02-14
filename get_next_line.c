/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 14:35:46 by aheister      #+#    #+#                 */
/*   Updated: 2021/02/02 08:06:56 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_nl(char *str)
{
	int i;

	if (!str)
		return(-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}

char	*ft_realloc(char *left, int len)
{
	char	*new_left;

	if (left)
	{
		new_left = (char *)malloc((len + 1) * sizeof(char));
		if (!new_left)
			return(0);
		return(new_left);
	}
	new_left = (char *)malloc((len + 1) * sizeof(char));
	if (!new_left)
		return(0);
	return(new_left);
}

char	*fill_join(char *left, char *buf, char *str_join)
{
	int i;
	int n;

	i = 0;
	n = 0;

	while (left[i] != '\0')
	{
		str_join[i] = left[i];
		i++;
	}
	while (buf[n] != '\0')
	{
		str_join[i + n] = buf[n];
		n++;
	}
	str_join[i + n] = '\0';
	return(str_join);
}

char	*ft_strjoin(char *left, char *buf)
{
	char	*str_join;	
	int	len;

	len = ft_strlen(left) + ft_strlen(buf);
	str_join = ft_realloc(left, len);
	if (str_join == 0)
		return(0);
	str_join = fill_join(left, buf, str_join);
	if (left)
		free(left);
	return(str_join);
}

char	*fill_str(char *str, int start, int type)
{
	int		i;
	int		len;
	char	*sub_str;

	if (!str)
		return(0);
	len = ft_strlen(str);
	if (type == 1)
		len = ft_nl(str);
	else if (type == 2)
		len = len - ft_nl(str);
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return(0);
	i = 0;
	while (i < len)
	{
		sub_str[i] = str[i + start];
		i++;
	}
	sub_str[i] = '\0';
	if (type == 2)
		free(str);
	return(sub_str);
}

char	*fill_left(char *left, char *buf)
{
	if (!buf)
		return(0);
	if (left)
	{
		left = ft_strjoin(left, buf);
		free(buf);
	}
	else
	{
		left = fill_str(buf, 0, 0);
		free(buf);
	}
	if (!left)
	{
		free(left);
		return(0);
	}
	return(left);
}

char	*fill_buf(int fd)
{
	char	*buf;
	int		ret;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return(0);
	ret = (int)read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
	{
		free(buf);
		return(0);
	}
	buf[ret] = '\0';
	return(buf);
}

int		get_line(int fd, char **line)
{
	static char	*left;
	char		*buf;

	if (!left)
		left = fill_str("", 0, 0);
	while (ft_nl(left) == -1)
	{
		buf = fill_buf(fd);
		if (buf == 0)
			return (-1);
		if (buf[0] == '\0')
		{
			*line = left;
			free(buf);
			return(0);
		}
		left = fill_left(left, buf);
		if 	(!left)
			return(-1);
	}
	*line = fill_str(left, 0, 1);
	left = fill_str(left, (ft_nl(left) + 1), 2);
	return(1);
}

int		get_next_line(int fd, char **line)
{
	int ret;

	if (!line || fd < 0)
		return (-1);
	ret = get_line(fd, line);
	return(ret);
}