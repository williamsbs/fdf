/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:02:45 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/13 11:28:47 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	res;
	int		signe;

	i = 0;
	res = 0;
	signe = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
				|| str[i] == 32 || str[i] == '\f')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		signe = (str[i] == '+') ? 1 : -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)res * signe);
}
