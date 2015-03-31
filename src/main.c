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
#include "command.h"
#include "libft.h"
#include "resolve.h"
#include <stdlib.h>

void	dlist_print(t_dlist *tmp)
{
	int		*nb;

	while (tmp != NULL)
	{
		nb = (int *)tmp->data;
		ft_putnbr(*nb);
		if (tmp->next != NULL)
			ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

t_dlist	*parse_args(int i, char **argv)
{
	t_dlist		*out;
	t_dlist		*elem;
	int			nb;

	out = NULL;
	i--;
	while (i)
	{
		nb = ft_atoi(argv[i]);
		elem = dlist_new(&nb, sizeof(int));
		dlist_add(&out, elem);
		i--;
	}
	return (out);
}

int		main(int argc, char **argv)
{
	t_dlist		*a;
	t_dlist		*b;

	a = parse_args(argc, argv);
	b = NULL;
	ft_putnbr(resolve(&a, &b));
	ft_putchar('\n');
	return (0);
}
