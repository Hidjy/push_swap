/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:52:54 by laime             #+#    #+#             */
/*   Updated: 2015/03/09 17:52:56 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define RA 1
# define RRA 2
# define PA 4
# define PB 8
# define SA 16
# define AS 32

# define V 1

# include "dlist.h"

void	push(t_dlist **src, t_dlist **dst);
void	r(t_dlist **list);
void	rr(t_dlist **list);
void	s(t_dlist **list);
void	do_command(int command, int mode, t_dlist **a, t_dlist **b);

#endif
