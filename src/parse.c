/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:56:21 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/18 15:00:24 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && i != 0)
			return (-1);
		if ((str[i] < 48 || str[i] > 57) && str[i] != '-')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_count(t_var *var)
{
	int i;

	i = 0;
	var->pars.county = 0;
	var->pars.countx = 0;
	while (var->pars.tab[i])
	{
		i++;
		var->pars.county++;
	}
	i = 0;
	while (var->pars.tab1[i])
	{
		i++;
		var->pars.countx++;
	}
	return (0);
}

void	ft_free_array(char **str)
{
	int y;

	y = 0;
	while (str[y] != 0)
	{
		free(str[y]);
		y++;
	}
	free(str);
}

int		ft_tab(t_var *var, int x, int y)
{
	if (ft_check(var->pars.tab1[x]) == -1)
		return (-1);
	var->pars.tabint[y][x] = ft_atoi(var->pars.tab1[x]);
	return (0);
}

int		ft_parse(t_var *var, int x, int y)
{
	char **temp;

	y = 0;
	var->pars.tab = ft_strsplit(var->pars.buf, '\n');
	while (var->pars.tab[y])
	{
		x = 0;
		temp = var->pars.tab1;
		var->pars.tab1 = ft_strsplit(var->pars.tab[y], ' ');
		if (temp != NULL)
			ft_free_array(temp);
		ft_count(var);
		if (var->pars.j == 0)
		{
			var->pars.tabint = ft_tabint(var->pars.county, var->pars.countx);
			var->pars.j++;
		}
		while (var->pars.tab1[x])
		{
			ft_tab(var, x, y);
			x++;
		}
		y++;
	}
	ft_free_array(var->pars.tab);
	return (0);
}
