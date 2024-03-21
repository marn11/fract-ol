/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:38:08 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/21 03:21:51 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max)
{
	return ((cmp_max - cmp_min) * (pos) / (w_max) + cmp_min);
}

void	pixel_check(int x, int y, t_fract *fractal)
{
	t_cmpx	z;
	t_cmpx	c;
	int		i;
	int		color;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = (scale_coords(x, -2, +2, WIDTH - 1) * fractal->zoom) + fractal->shift_x;
	c.i = (scale_coords(y, +2, -2, HEIGHT - 1) * fractal->zoom)+ fractal->shift_y;
	while (i < fractal->iter_max)
	{
		z = total(z,c);
		if ((z.r * z.r) + (z.i * z.i) > HYPO) // magnitude : bch7al b3id 3la l origin
		{
			color = scale_coords(i, BLACK, WHITE, fractal->iter_max);
			my_pixel_put(&fractal->img , x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractal->img, x, y, BLACK);
}
