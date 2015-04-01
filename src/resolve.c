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

int		is_almost_sorted(t_dlist *list)
{
	t_dlist	*tmp;
	int		len;
	int		*nb;
	int		*last;

	len = 0;
	tmp = list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = list;
	if (len <= 3)
		return (0);
	last = (int *)tmp->data;
	while (len-- > 1)
	{
		nb = (int *)tmp->data;
		if (*last > *nb)
			return (0);
		last = nb;
		tmp = tmp->next;
	}
	return (1);
}

int		resolve(t_dlist **a, t_dlist **b, int mode)
{
	int		*nb;
	int		i;

	i = 0;
	while ((*a != NULL) && (*b != NULL || check(*a) == 0))
	{
		nb = (int *)(*a)->data;
		if (!(*b) && (*a)->next != NULL && *((int *)(*a)->next->data) < *nb)
			do_command(SA, mode, a, b);
		else if (*b == NULL && is_almost_sorted(*a))
			do_command(AS, mode, a, b),
			i += 4;
		else if (*nb == get_lowest(*a))
			do_command(PB, mode, a, b);
		else if (is_rr_better(*a))
			do_command(RRA, mode, a, b);
		else
			do_command(RA, mode, a, b);
		i++;
	}
	while (*b != NULL && i++)
		do_command(PA, mode, a, b);
	if (!(mode & V))
		ft_putchar('\n');
	return (i);
}
