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
	t_dlist		*b;

	if (argc != 2)
		return (0);
	a = parse_args(argv);
	b = NULL;
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	r(&a);
	r(&b);
	dlist_print(a);
	dlist_print(b);
	return (0);
}
