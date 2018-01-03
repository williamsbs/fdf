/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:39:07 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/18 14:41:09 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_draw1(t_var var, t_draw l, int color)
{
	int i;

	l.cumul = l.dx / 2;
	i = 0;
	while (i <= l.dx)
	{
		i++;
		l.x += l.xplus;
		l.cumul += l.dy;
		if (l.cumul >= l.dx)
		{
			l.cumul -= l.dx;
			l.y += l.yplus;
		}
		mlx_pixel_put_to_image(var.draw, l.x, l.y, color);
	}
}

static void		ft_draw2(t_var var, t_draw l, int color)
{
	int i;

	l.cumul = l.dy / 2;
	i = 0;
	while (i <= l.dy)
	{
		i++;
		l.y += l.yplus;
		l.cumul += l.dx;
		if (l.cumul >= l.dy)
		{
			l.cumul -= l.dy;
			l.x += l.xplus;
		}
		mlx_pixel_put_to_image(var.draw, l.x, l.y, color);
	}
}

void			ft_draw(t_var *var, int color)
{
	t_draw l;

	l.x = var->draw.xi;
	l.y = var->draw.yi;
	l.dx = var->draw.xf - var->draw.xi;
	l.dy = var->draw.yf - var->draw.yi;
	l.xplus = (l.dx > 0) ? 1 : -1;
	l.yplus = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	mlx_pixel_put_to_image(var->draw, l.x, l.y, color);
	if (l.dx > l.dy)
		ft_draw1(*var, l, color);
	else
		ft_draw2(*var, l, color);
}

void			ft_pos_sd(t_var *var, int x, int y)
{
	if (y != 0)
	{
		var->draw.xi = var->draw.tabposx[y][x] + var->pars.tabint[y][x] * 0.2\
		* var->draw.relief + var->draw.movex;
		var->draw.yi = var->draw.tabposy[y][x] + var->pars.tabint[y][x] * 0.2\
		* var->draw.relief + var->draw.movey;
		var->draw.xf = var->draw.tabposx[y - 1][x] + var->pars.tabint[y - 1][x]\
		* 0.2 * var->draw.relief + var->draw.movex;
		var->draw.yf = var->draw.tabposy[y - 1][x] + var->pars.tabint[y - 1][x]\
		* 0.2 * var->draw.relief + var->draw.movey;
		if (var->pars.tabint[y][x] == 0 || var->pars.tabint[y][x] < 0)
			ft_draw(var, 0x0000FF);
		else if (var->pars.tabint[y][x] > 0 && var->pars.tabint[y][x] < 10)
			ft_draw(var, 0x339933);
		else if (var->pars.tabint[y][x] > 10 && var->pars.tabint[y][x] < 20)
			ft_draw(var, 0x785E2F);
		else
			ft_draw(var, 0x462E01);
	}
}

void			ft_pos(t_var *var, int x, int y)
{
	if (x != 0)
	{
		var->draw.xi = var->draw.tabposx[y][x] + var->pars.tabint[y][x] * \
		0.2 * var->draw.relief + var->draw.movex;
		var->draw.yi = var->draw.tabposy[y][x] + var->pars.tabint[y][x] * \
		0.2 * var->draw.relief + var->draw.movey;
		var->draw.xf = var->draw.tabposx[y][x - 1] + var->pars.tabint[y][x - 1]\
		* 0.2 * var->draw.relief + var->draw.movex;
		var->draw.yf = var->draw.tabposy[y][x - 1] + var->pars.tabint[y][x - 1]
		* 0.2 * var->draw.relief + var->draw.movey;
		if (var->pars.tabint[y][x] == 0 || var->pars.tabint[y][x] < 0)
			ft_draw(var, 0x0000FF);
		else if (var->pars.tabint[y][x] > 0 && var->pars.tabint[y][x] < 10)
			ft_draw(var, 0x339933);
		else if (var->pars.tabint[y][x] > 10 && var->pars.tabint[y][x] < 20)
			ft_draw(var, 0x785E2F);
		else
			ft_draw(var, 0x462E01);
	}
	ft_pos_sd(var, x, y);
}
