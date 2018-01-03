/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:53:46 by wsabates          #+#    #+#             */
/*   Updated: 2017/12/14 15:10:03 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"

# define BUFF_SIZE 0xfffff
# define WINSIZE_X 800
# define WINSIZE_Y 800

typedef struct	s_parse
{

	char	**tab;
	char	**tab1;
	int		j;
	int		county;
	int		countx;
	int		**tabint;
	char	buf[BUFF_SIZE + 1];
	int		fd;
}				t_parse;

typedef struct	s_draw
{
	void	*mlx;
	void	*win;
	int		i;
	int		x;
	int		y;
	int		dx;
	int		dy;
	void	*img;
	char	*map;
	int		bpp;
	int		size_line;
	int		endian;
	double	xplus;
	double	yplus;
	double	x_max;
	double	y_max;
	double	cumul;
	double	posx;
	double	posy;
	double	padx;
	double	pady;
	double	xi;
	double	yi;
	double	xf;
	double	yf;
	double	z;
	int		xpix;
	int		ypix;
	int		**tabposx;
	int		**tabposy;
	int		zoom;
	int		movex;
	int		movey;
	int		relief;
}				t_draw;

typedef struct	s_var
{
	t_parse		pars;
	t_draw		draw;

}				t_var;

void			ft_draw(t_var *var, int color);
void			ft_aff(void);
int				ft_mlx(t_var *var);
void			ft_pos(t_var *var, int x, int y);
int				ft_parse(t_var *var, int x, int y);
void			ft_map(t_var *var);
int				ft_init_struct(t_var *var);
int				ft_init_struct2(t_var *var);
void			mlx_pixel_put_to_image(t_draw draw, int x, int y, int color);
void			ft_free_2Darray3(int **str);
#endif
