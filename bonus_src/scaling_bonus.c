/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:25:59 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/29 01:47:23 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol.h"

double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max)
{
	return ((cmp_max - cmp_min) * (pos) / (w_max) + cmp_min);
}

t_cmpx	total(t_cmpx z, t_cmpx c, t_fract *fract)
{
	t_cmpx	z_2;
	t_cmpx	z_2_c;

	z_2 = cmpx_pow(z, !ft_strcmp(fract->title, "tricorn"));
	z_2_c = cmpx_sum(z_2, c);
	return (z_2_c);
}

void	toggle_fracts(t_cmpx *z, t_cmpx *c, t_fract *fractal)
{
	if (!ft_strcmp(fractal->title, "mandelbrot"))
	{
		c->r = z->r;
		c->i = z->i;
	}
	else if (!ft_strcmp(fractal->title, "tricorn"))
	{
		c->r = z->r;
		c->i = z->i;
	}
	else
	{
		c->r = fractal->julia_x;
		c->i = fractal->julia_y;
	}
}

void	pixel_check(int x, int y, t_fract *fractal)
{
	t_cmpx	z;
	t_cmpx	c;
	int		i;
	int		color;

	i = 0;
	z.r = (scale_coords(x, fractal->start_pos_x, fractal->end_pos_x,
				WIDTH - 1)) + fractal->shift_x;
	z.i = (scale_coords(y, fractal->end_pos_y, fractal->start_pos_y,
				HEIGHT - 1)) + fractal->shift_y;
	toggle_fracts(&z, &c, fractal);
	while (i < fractal->iter_max)
	{
		z = total(z, c, fractal);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			color = scale_coords(i, BLACK, WHITE, fractal->color * 3);
			my_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractal->img, x, y, 0x000000);
}
