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

	if (list == NULL)
		return ;
	new = dlist_new((*list)->data, (*list)->size);
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
