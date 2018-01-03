/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:23:22 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/14 12:25:25 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_aff(void)
{
	ft_putstr("\n -------------------------------------------- ");
	ft_putstr("\n|                            ^               |");
	ft_putstr("\n|            You can move  <   >             |");
	ft_putstr("\n|                            v               |");
	ft_putstr("\n|       You can zoom with '/' & '*'          |");
	ft_putstr("\n|                                            |");
	ft_putstr("\n|  You can inc. & dec. depth with '+' & '-'  |");
	ft_putstr("\n|                                            |");
	ft_putstr("\n|        You can shut down with 'esc'        |");
	ft_putstr("\n --------------------------------------------\n\n");
}
