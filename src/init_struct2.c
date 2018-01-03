/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:03:10 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/14 12:27:37 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_init_struct2(t_var *var)
{
	ft_aff();
	var->pars.j = 0;
	var->pars.tab = NULL;
	var->draw.relief = 1;
	var->draw.movex = 0;
	var->draw.movey = 0;
	var->draw.zoom = 0;
	var->draw.mlx = mlx_init();
	var->draw.win = mlx_new_window(var->draw.mlx, WINSIZE_X, WINSIZE_Y, \
		"mlx 42");
	var->draw.img = mlx_new_image(var->draw.mlx, WINSIZE_X, WINSIZE_Y);
	var->draw.map = mlx_get_data_addr(var->draw.img, &var->draw.bpp, \
		&var->draw.size_line, &var->draw.endian);
	return (0);
}
