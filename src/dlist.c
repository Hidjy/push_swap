/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:52:54 by laime             #+#    #+#             */
/*   Updated: 2015/03/09 17:52:56 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include "libft.h"
#include <stdlib.h>

t_dlist		*dlist_new(const void *content, size_t content_size)
{
	t_dlist	*out;

	out = (t_dlist *)malloc(sizeof(t_dlist));
	if (out == NULL)
		return (NULL);
	out->size = (content != NULL) ? content_size : 0;
	out->data = ft_memalloc(out->size);
	out->data = ft_memcpy(out->data, content, out->size);
	out->next = NULL;
	out->prev = NULL;
	return (out);
}

void		dlist_add(t_dlist **list, t_dlist *elem)
{
	elem->prev = NULL;
	elem->next = *list;
	if (*list != NULL)
		(*list)->prev = elem;
	*list = elem;
}

void		dlist_pushback(t_dlist **list, t_dlist *elem)
{
	t_dlist		*tmp;

	tmp = *list;
	while (tmp != NULL && tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	elem->prev = tmp;
	if (tmp != NULL)
		(tmp)->next = elem;
	else
		*list = elem;
	elem->next = NULL;
}
