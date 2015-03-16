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

void	pushb(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;
	t_dlist	*new;

	if (b == NULL)
		return ;
	tmp = *a;
	new = dlist_new(tmp->data, tmp->size);
	dlist_add(b, new);
	dlist_cuthead(a);
}
