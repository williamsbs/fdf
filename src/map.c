/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:49:33 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/18 14:44:58 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_map(t_var *var)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	var->draw.tabposy = ft_tabint(var->pars.county, var->pars.countx);
	var->draw.tabposx = ft_tabint(var->pars.county, var->pars.countx);
	while (y < (var->draw.y_max))
	{
		x = 0;
		while (x < var->draw.x_max)
		{
			var->draw.tabposx[y][x] = x * var->draw.padx + var->draw.xpix;
			var->draw.tabposy[y][x] = y * var->draw.pady + var->draw.ypix;
			ft_pos(var, x, y);
			x++;
		}
		y++;
	}
}
