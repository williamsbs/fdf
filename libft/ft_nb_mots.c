/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_mot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:46:25 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/15 13:55:42 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nb_mots(char *str, char separateur)
{
	int	i;
	int	nb_mots;

	i = 0;
	nb_mots = 0;
	while (str[i])
	{
		if (str[i] == separateur)
			i++;
		else
		{
			while (str[i] != separateur && str[i])
				i++;
			nb_mots++;
		}
	}
	return (nb_mots);
}
