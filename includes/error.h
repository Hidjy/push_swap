/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:32:32 by laime             #+#    #+#             */
/*   Updated: 2015/04/01 16:32:41 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "dlist.h"

int		error_handling(char **argv);
int		ft_atoi_err(const char *str, int *err);
void	quit(char *msg, int fd);

#endif
