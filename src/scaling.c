/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:38:08 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/25 02:14:48 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max)
{
	return ((cmp_max - cmp_min) * (pos) / (w_max) + cmp_min);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_cmpx	total(t_cmpx z, t_cmpx c)
{
	t_cmpx	z_2;
	t_cmpx	z_2_c;

	z_2 = cmpx_pow(z);
	z_2_c = cmpx_sum(z_2, c);
	return (z_2_c);
}

void	toggle_fracts(t_cmpx *z, t_cmpx *c, t_fract *fractal)
{
	if (!ft_strncmp(fractal->title, "mandelbrot", 10))
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
	z.i = (scale_coords(y, fractal->start_pos_y, fractal->end_pos_y,
				HEIGHT - 1)) + fractal->shift_y;
	toggle_fracts(&z, &c, fractal);
	while (i < fractal->iter_max)
	{
		z = total(z, c);
		if ((z.r * z.r) + (z.i * z.i) > HYPO)
		{
			color = create_trgb(0, 1.3 * i / fractal->iter_max * 255
					* fractal->color, 1.5 * i * fractal->color, 1.7
					* i * fractal->color);
			my_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractal->img, x, y, BLACK);
}
