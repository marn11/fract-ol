/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:34:22 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/18 20:52:19 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "utils/utils.h"

# define WIDTH 800
# define HEIGHT 800
# define HYPO 4
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PURPLE 0x3A2170
# define ORANGE 0xDB831C
# define RED 0xBE2924
# define PINK 0xDE4959
# define BLUE 0x11808C
# define PALE 0xF5E8C7
# define SKY_BLUE 0x4F94CD
# define GREEN 0x1B4242
# define LIGHT_PINK 0xDA0C81
# define DARK_PINK 0xAE445A

typedef struct s_img
{
	void	*image; // img struct pointer
	char	*pixels; // actual pixels pointer
	int		bpp;//bits per pixel aka size of each pixel //  number of distinct colors that can be represented by each pixel
	int		endian;
	int		llen; // if width 800 and each pixel 4 bytes 800* 4 in bytes
	char	*addr;
}	t_img;
typedef struct s_cmpx
{
	double r;
	double i;
}	t_cmpx;

typedef struct s_fract
{
	char	*title;
	void	*connection;
	void	*window;
	t_img	img;
	t_cmpx	z;
	t_cmpx	c;
	double	iter_max;
}	t_fract;

void	init(t_fract *fractal);
void	render(t_fract *fractal);
double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max);
void	values(t_fract *fractal);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	render(t_fract *fractal);
void	pixel_check(int x, int y, t_fract *fractal);

#endif
