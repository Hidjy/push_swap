/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:56:11 by laime             #+#    #+#             */
/*   Updated: 2014/11/23 13:56:13 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t			j;
	char			*temp;
	char			*dst;

	j = 0;
	if (!len)
	{
		dst = (char *)malloc(sizeof(char));
		*dst = 0;
		return (dst);
	}
	if (!s || !*s)
		return (NULL);
	temp = ft_memalloc(len);
	if (!temp)
		return (NULL);
	dst = temp;
	while (j < len)
	{
		temp[j] = s[start];
		j++;
		start++;
	}
	temp[j] = '\0';
	return (dst);
}
