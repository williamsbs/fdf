/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_mot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:45:59 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/15 11:46:10 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_index_mot(char *str, int mot, char separateur)
{
	int	i;
	int	compteur_mots;

	i = 0;
	compteur_mots = 0;
	while (str[i])
	{
		while (str[i] == separateur)
			i++;
		if (compteur_mots == mot)
			return (i);
		while (str[i] != separateur && str[i])
			i++;
		compteur_mots++;
	}
	return (0);
}
