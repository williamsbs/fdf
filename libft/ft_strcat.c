/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:29:52 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/10 18:27:34 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int taille;

	i = 0;
	taille = 0;
	while (s1[i] != '\0')
	{
		taille++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s1[taille + i] = s2[i];
		i++;
	}
	s1[taille + i] = '\0';
	return (s1);
}
