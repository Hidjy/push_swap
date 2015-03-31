/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:52:54 by laime             #+#    #+#             */
/*   Updated: 2015/03/09 17:52:56 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "libft.h"
#include "command.h"

void	push(t_dlist **src, t_dlist **dst)
{
	t_dlist	*tmp;
	t_dlist	*new;

	if (src == NULL)
		return ;
	tmp = *src;
	new = dlist_new(tmp->data, tmp->size);
	dlist_add(dst, new);
	dlist_cuthead(src);
}

void	r(t_dlist **list)
{
	t_dlist	*new;

	if (list == NULL)
		return ;
	new = dlist_new((*list)->data, (*list)->size);
	dlist_pushback(list, new);
	dlist_cuthead(list);
}

void	rr(t_dlist **list)
{
	t_dlist	*new;
	t_dlist	*tmp;

	if (list == NULL)
		return ;
	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = dlist_new(tmp->data, tmp->size);
	dlist_add(list, new);
	dlist_cuttail(list);
}

void	s(t_dlist **list)
{
	void	*tmp;
	size_t	tmp_s;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return ;
	tmp = (*list)->data;
	tmp_s = (*list)->size;
	(*list)->data = (*list)->next->data;
	(*list)->size = (*list)->next->size;
	(*list)->next->data = tmp;
	(*list)->next->size = tmp_s;
}

void	do_command(int command, int mode, t_dlist **a, t_dlist **b)
{
	if (command & RA)
		r(a), ft_putstr("ra");
	if (command & RRA)
		rr(a), ft_putstr("rra");
	if (command & PA)
		push(b, a), ft_putstr("pa");
	if (command & PB)
		push(a, b), ft_putstr("pb");
	if (command & SA)
		s(a), ft_putstr("sa");
	if (command & AS)
		do_command(RRA, mode, a, b),
		do_command(RRA, mode, a, b),
		do_command(SA, mode, a, b),
		do_command(RA, mode, a, b),
		do_command(RA, mode, a, b);
	else if (mode & V)
	{
		ft_putstr(":\n");
		dlist_print(*a);
		dlist_print(*b);
		ft_putchar('\n');
	}
	else
		ft_putchar(' ');
}
