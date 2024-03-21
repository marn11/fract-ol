/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:34:22 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/21 03:38:35 by mbenchel         ###   ########.fr       */
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
# define SPACE 49
# define ESC 53
# define ENTER 36
# define PLUS 69
# define MINUS 78
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ZOOM_IN_MOUSE 4
# define ZOOM_OUT_MOUSE 5
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define BLACK 0x000000
# define WHITE 0xFFFFFF
// # define PURPLE 0x3A2170
// # define ORANGE 0xDB831C
# define ORANGE 0xFDAF7B
// # define RED 0xBE2924
// # define BLUE 0x11808C
// # define PALE 0xF5E8C7
// # define SKY_BLUE 0x4F94CD
// # define GREEN 0x1B4242
# define PINK 0xDE4959
# define LIGHT_PINK 0xDA0C81
# define DARK_PINK 0xAE445A
# define BLUE        0x0000FF
# define DARK_BLUE   0x00137F
# define PURPLE      0x7F00FF
# define DARK_PURPLE 0x330066
// # define RED         0xFF0000
# define RED         0xFF204E
# define DARK_RED    0x660000
# define YELLOW      0xFFFF00
// # define ORANGE      0xFF7F00
# define LIGHT_GRAY  0xC0C0C0
# define DARK_GRAY   0x404040
# define GREEN       0x00FF00
# define DARK_GREEN  0x006600
// palette

# define NAVY  0x496989
# define TEAL  0x58A399
# define TEALL  0xFF8F8F
# define DGREEN  0xA8CD9F
# define LIGHT_GREEN  0xE2F4C5


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
	double	zoom;
	double	shift_y;
	double	shift_x;
}	t_fract;

void	init(t_fract *fractal);
void	render(t_fract *fractal);
double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max);
void	values(t_fract *fractal);
void	my_pixel_put(t_img *img, int x, int y, int color);
int		mouse_press(int button, int x, int y, t_fract *fractal);
void	render(t_fract *fractal);
void	pixel_check(int x, int y, t_fract *fractal);
void	events(t_fract *fractal);
int		key_press(int keycode, t_fract *fractal);
int		close_window(t_fract *fractal);
t_cmpx	cmpx_sum(t_cmpx z, t_cmpx x);
t_cmpx	cmpx_pow(t_cmpx z);
t_cmpx	total(t_cmpx z, t_cmpx c);
double	atof(char	*s);

#endif
