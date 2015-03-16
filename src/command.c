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
