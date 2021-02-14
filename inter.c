/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aheister <aheister@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 14:09:47 by aheister      #+#    #+#                 */
/*   Updated: 2021/01/31 14:24:47 by aheister      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_same(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return(0);
}

int		check_earlier(char *str, char c, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return(0);
}

void	unions(char *stra, char *strb)
{	
	int i;

	i = 0;
	while (stra[i] != '\0')
	{
		if (check_same(strb, stra[i]) == 1)
		{
			if (check_earlier(stra, stra[i], i) == 0)
				write(1, &stra[i], 1);
		}
		i++;
	}
}

int     main(int argc, char **argv)
{
	if (argc == 3)
		unions(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}