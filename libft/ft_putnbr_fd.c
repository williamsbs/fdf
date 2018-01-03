/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:16:55 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/13 11:26:37 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long res;

	res = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = -res;
	}
	if (res >= 10)
	{
		ft_putnbr_fd(res / 10, fd);
	}
	ft_putchar_fd(res % 10 + '0', fd);
}
