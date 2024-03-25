/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:34:22 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/25 20:18:29 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <limits.h>
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
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define RESET "\x1b[0m"

typedef struct s_img
{
	void	*image;
	char	*pixels;
	int		bpp;
	int		endian;
	int		llen;
	char	*addr;
}	t_img;
typedef struct s_cmpx
{
	double	r;
	double	i;
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
	double	color;
	double	zoom;
	double	shift_y;
	double	shift_x;
	double	julia_x;
	double	julia_y;
	double	start_pos_x;
	double	start_pos_y;
	double	end_pos_x;
	double	end_pos_y;
}	t_fract;

void	ft_putstr_fd(char *s, int fd);
void	init(t_fract *fractal);
void	render(t_fract *fractal);
void	values(t_fract *fractal);
void	my_pixel_put(t_img *image, int x, int y, int color);
void	render(t_fract *fractal);
void	pixel_check(int x, int y, t_fract *fractal);
void	events(t_fract *fractal);
double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max);
double	ft_atod(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		mouse_press(int button, int x, int y, t_fract *fractal);
int		key_press(int keycode, t_fract *fractal);
int		close_window(t_fract *fractal);
t_cmpx	cmpx_sum(t_cmpx z, t_cmpx x);
t_cmpx	cmpx_pow(t_cmpx z);
t_cmpx	total(t_cmpx z, t_cmpx c);
size_t	ft_strlen(const char *s);

#endif
