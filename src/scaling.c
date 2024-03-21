/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:38:08 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/21 17:55:52 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max)
{
	return ((cmp_max - cmp_min) * (pos) / (w_max) + cmp_min);
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
	z.r = (scale_coords(x, -2, +2, WIDTH - 1) * fractal->zoom) + fractal->shift_x;
	z.i = (scale_coords(y, +2, -2, HEIGHT - 1) * fractal->zoom)+ fractal->shift_y;
	toggle_fracts(&z, &c, fractal);
	while (i < fractal->iter_max)
	{
		z = total(z,c);
		if ((z.r * z.r) + (z.i * z.i) > HYPO) // magnitude : bch7al b3id 3la l origin
		{
			color = scale_coords(i, BLACK, WHITE, fractal->iter_max); //testi hadi *10
			my_pixel_put(&fractal->img , x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractal->img, x, y, BLACK);
}
