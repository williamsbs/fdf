/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:33:14 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/10 15:26:34 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	char		*srcs;

	i = 0;
	dest = (char*)dst;
	srcs = (char*)src;
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dest);
}
