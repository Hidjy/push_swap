/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:52:54 by laime             #+#    #+#             */
/*   Updated: 2015/03/09 17:52:56 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "libft.h"
#include <stdlib.h>

void	free_dlist(t_dlist *elem)
{
	if (elem != NULL)
	{
		if (elem->data != NULL)
			free(elem->data);
		free(elem);
	}
}

t_dlist	*parse_args(char **argv)
{
	t_dlist		*out;
	t_dlist		*elem;
	char		**cmds;
	int			i;
	int			nb;

	out = NULL;
	cmds = ft_strsplit(argv[1], ' ');
	i = 0;
	while (cmds[i] != NULL)
		i++;
	i--;
	while (i >= 0)
	{
		nb = ft_atoi(cmds[i]);
		elem = dlist_new(&nb, sizeof(int));
		dlist_add(&out, elem);
		i--;
	}
	return (out);
}

int		main(int argc, char **argv)
{
	t_dlist		*a;

	if (argc != 2)
		return (0);
	a = parse_args(argv);

	t_dlist		*tmp;
	tmp = a;
	while (tmp != NULL)
	{
		int *nb;
		nb = (int *)tmp->data;
		ft_putnbr(*nb);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	return (0);
}
