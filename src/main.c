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
#include "error.h"
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

int		dlist_search(t_dlist *tmp, void *data, size_t size)
{
	while (tmp != NULL)
	{
		if (ft_memcmp(tmp->data, data, size) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_dlist	*parse_args(int i, char **argv)
{
	t_dlist		*out;
	t_dlist		*elem;
	int			nb;
	int			err;

	out = NULL;
	i--;
	while (i)
	{
		nb = ft_atoi_err(argv[i], &err);
		if (err)
			quit("Error\n", 2);
		if (dlist_search(out, &nb, sizeof(int)))
			quit("Error\n", 2);
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
	int			opts;

	opts = 0;
	if (argc > 2 && ft_strcmp(argv[1], "-v") == 0)
		opts += V, argv++, argc--;
	if (error_handling(argv) == 0)
		quit("Usage: ./push_swap [-v] [number ...]\n", 2);
	a = parse_args(argc, argv);
	b = NULL;
	if (NB)
	{
		ft_putnbr(resolve(&a, &b));
		ft_putchar('\n');
	}
	else
		resolve(&a, &b);
	return (0);
}
