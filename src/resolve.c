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

int		get_lowest(t_dlist *a)
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

int		is_rr_better(t_dlist *a)
{
	t_dlist		*tmp;
	int			len;
	int			lowest;

	if (a == NULL)
		return (0);
	lowest = get_lowest(a);
	tmp = a;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	len /= 2;
	tmp = a;
	while (len >= 0)
	{
		len--;
		if (*((int *)tmp->data) == lowest)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	resolve(t_dlist **a, t_dlist **b)
{
	int		*nb;

	while (*b != NULL || check(*a) == 0)
	{
		if (*a == NULL)
		{
			while (*b != NULL)
			{
				push(b, a);
				ft_putstr("pa ");
			}
		}
		else
		{
			nb = (int *)(*a)->data;
			if ((*a)->next != NULL && *((int *)(*a)->next->data) == get_lowest(*a))
			{
				s(a);
				ft_putstr("sa ");
			}
			else if (*nb != get_lowest(*a))
			{
				if (is_rr_better(*a))
				{
					rr(a);
					ft_putstr("rra ");
				}
				else
				{
					r(a);
					ft_putstr("ra ");
				}
			}
			else
			{
				push(a, b);
				ft_putstr("pb ");
			}
		}
	}
	ft_putchar('\n');
}
