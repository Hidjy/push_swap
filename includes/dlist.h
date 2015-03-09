/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:52:54 by laime             #+#    #+#             */
/*   Updated: 2015/03/09 17:52:56 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <string.h>

typedef struct		s_dlist
{
	void			*data;
	size_t			size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

#endif
