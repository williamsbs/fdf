/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:11:54 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/14 15:23:29 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_open(t_var *var, char *argv)
{
	if ((var->pars.fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	var->pars.buf[read(var->pars.fd, var->pars.buf, BUFF_SIZE)] = '\0';
	if ((var->pars.buf[0] < 48 || var->pars.buf[0] > 57) && var->pars.buf[0] \
	!= ' ' && var->pars.buf[0] != '\n')
		return (-1);
	close(var->pars.fd);
	return (0);
}

void	ft_keyfunc(int keycode, t_var *var)
{
	if (keycode == 69)
		var->draw.relief += 2;
	if (keycode == 78)
		var->draw.relief -= 2;
	if (keycode == 124)
		var->draw.movex += 8;
	if (keycode == 123)
		var->draw.movex -= 8;
	if (keycode == 125)
		var->draw.movey += 8;
	if (keycode == 126)
		var->draw.movey -= 8;
	if (keycode == 67)
		var->draw.zoom += 3;
	if (keycode == 75)
		var->draw.zoom -= 3;
}

int		my_key_funct(int keycode, t_var *var)
{
	if (keycode == 53)
		exit(1);
	ft_keyfunc(keycode, var);
	mlx_destroy_image(var->draw.mlx, var->draw.img);
	var->draw.img = mlx_new_image(var->draw.mlx, WINSIZE_X, WINSIZE_Y);
	var->draw.map = mlx_get_data_addr(var->draw.img, &var->draw.bpp, \
		&var->draw.size_line, &var->draw.endian);
	ft_init_struct(var);
	ft_map(var);
	mlx_put_image_to_window(var->draw.mlx, var->draw.win, \
		var->draw.img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_var		var;
	int			y;
	int			x;

	y = 0;
	x = 0;
	if (argc != 2)
		return (-1);
	if ((ft_open(&var, argv[1])) == -1)
	{
		ft_putstr("Not a valid map");
		return (1);
	}
	ft_init_struct2(&var);
	if (ft_parse(&var, x, y) == -1)
	{
		ft_putstr("Not a valid map");
		return (0);
	}
	mlx_hook(var.draw.win, 2, (1L << 0), my_key_funct, &var);
	ft_init_struct(&var);
	ft_map(&var);
	mlx_put_image_to_window(var.draw.mlx, var.draw.win, var.draw.img, 0, 0);
	mlx_loop(var.draw.mlx);
	return (0);
}
