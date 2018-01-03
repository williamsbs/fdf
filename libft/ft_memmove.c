/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:27:07 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/15 09:21:33 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*srcs;

	dest = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	if (srcs == dest)
		return (dest);
	if (srcs < dest)
	{
		srcs = (unsigned char*)src + len - 1;
		dest = (unsigned char*)dst + len - 1;
		while (len-- > 0)
		{
			*dest-- = *srcs--;
		}
	}
	else
	{
		while (len-- > 0)
		{
			*dest++ = *srcs++;
		}
	}
	return (dst);
}
