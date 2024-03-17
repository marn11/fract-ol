/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:38:08 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/17 03:30:43 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max)
{
	return ((cmp_max - cmp_min) * (pos) / (w_max) + cmp_min);
}

t_cmpx	cmpx_sum(t_cmpx z, t_cmpx x)
{
	t_cmpx	res;

	res.r = z.r + x.r;
	res.i = z.i + x.i;
	return (res);
}

t_cmpx	cmpx_pow(t_cmpx z)
{
	t_cmpx	res;

	res.r = (z.r * z.r) - (z.i * z.i);
	res.i = 2 * z.r * z.i;
	return (res);
}

t_cmpx	total(t_cmpx z, t_cmpx c)
{
	t_cmpx	z_2;
	t_cmpx	z_2_c;

	z_2 = cmpx_pow(z);
	z_2_c = cmpx_sum(z_2, c);
	return (z_2_c);
}

void	pixel_check(int x, int y, t_fract *fractal)
{
	t_cmpx	z;
	t_cmpx	c;
	int		i;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = scale_coords(x, -2, +2, WIDTH - 1);
	c.i = scale_coords(y, +2, -2, HEIGHT - 1);
	while (i < ITER_MAX)
	{
		z = total(z,c);
		if ((z.r * z.r) + (z.i * z.i) > HYPO)
		{
			my_pixel_put();
			return ;
		}
	}
}
