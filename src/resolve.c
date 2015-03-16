/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
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

int		check(t_dlist *a)
{
	int		*nb;
	int		*last;

	if (a == NULL)
		return (1);
	last = (int *)a->data;
	while (a)
	{
		nb = (int *)a->data;
		if (*last > *nb)
			return (0);
		last = nb;
		a = a->next;
	}
	return (1);
}

int		get_lower(t_dlist *a)
{
	int		*nb;
	int		*last;

	if (a == NULL)
		return (0);
	last = (int *)a->data;
	while (a)
	{
		nb = (int *)a->data;
		if (*last > *nb)
			last = nb;
		a = a->next;
	}
	return (*last);
}

void	resolve(t_dlist **a, t_dlist **b)
{
	int		*nb;

	while (*b != NULL || check(*a) == 0)
	{
		if (*a == NULL)
		{
			while (*b != NULL)
				push(b, a);
		}
		else
		{
			nb = (int *)(*a)->data;
			while (*nb != get_lower(*a))
			{
				r(a);
				nb = (int *)(*a)->data;
			}
			push(a, b);
		}
	}
}
