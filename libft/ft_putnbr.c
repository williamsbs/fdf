/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:46:35 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/13 11:23:11 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long res;

	res = (long)n;
	if (n < 0)
	{
		ft_putchar('-');
		res = -res;
	}
	if (res >= 10)
	{
		ft_putnbr(res / 10);
	}
	ft_putchar(res % 10 + '0');
}
