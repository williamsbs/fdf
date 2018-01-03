/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:26:53 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/14 19:06:30 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			compteur_size(long nbr)
{
	int size;

	size = 0;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size + 1);
}

static char			remplissage(int indice, long nbr)
{
	int i;

	i = 0;
	while (i < indice)
	{
		nbr = nbr / 10;
		i++;
	}
	return (nbr % 10 + '0');
}

char				*ft_itoa(int n)
{
	int		neg;
	int		size;
	int		indice;
	char	*str;
	long	nbr;

	nbr = (long)n;
	neg = 0;
	indice = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		neg = 1;
	}
	size = compteur_size(nbr);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (size--)
	{
		str[size] = remplissage(indice, nbr);
		indice += 1;
	}
	if (neg == 1)
		str = ft_strjoin("-\0", str);
	return (str);
}
