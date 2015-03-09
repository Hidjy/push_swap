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
