/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_ltr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:48:03 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/15 11:48:16 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nb_ltr(char *str, int mot, char separateur)
{
	int	index;
	int	nb_lettres;

	index = ft_index_mot(str, mot, separateur);
	nb_lettres = 0;
	while (str[index] != separateur && str[index])
	{
		nb_lettres++;
		index++;
	}
	return (nb_lettres);
}
