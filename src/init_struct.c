/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:51:18 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/14 12:09:42 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_init_struct(t_var *var)
{
	var->draw.x_max = var->pars.countx;
	var->draw.y_max = var->pars.county;
	var->draw.padx = (((WINSIZE_X / 3) * 2) / var->draw.x_max) \
	+ var->draw.zoom;
	var->draw.pady = (((WINSIZE_Y / 3) * 2) / var->draw.y_max) \
	+ var->draw.zoom;
	var->draw.xpix = ((WINSIZE_X / 3) / 2);
	var->draw.ypix = ((WINSIZE_Y / 3) / 2);
	return (0);
}
