/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:14:20 by wsabates          #+#    #+#             */
/*   Updated: 2017/11/09 15:37:58 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char*)s;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == c)
	{
		return (&ret[i]);
	}
	else
	{
		return (NULL);
	}
	return (0);
}
