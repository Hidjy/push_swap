/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:32:08 by laime             #+#    #+#             */
/*   Updated: 2015/03/31 20:32:10 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

void	quit(char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(0);
}

int		ft_atoi_err(const char *str, int *err)
{
	unsigned int	ret;
	unsigned int	prev;
	char			si;

	ret = 0;
	si = 1;
	*err = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\n' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		si = (*str++ == '-' ? -1 : 1);
	while (ft_isdigit(*str))
	{
		prev = ret;
		ret = ret * 10 + (*str - '0');
		if (prev > ret)
			*err = 1;
		str++;
	}
	if ((ret - 1 > INT_MAX && si < 0) || (ret > INT_MAX && si > 0))
		*err = 1;
	return (si * ret);
}

int		error_handling(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		if (!ft_isdigit(argv[i][0]) && argv[i][0] != '-')
		{
			return (0);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
