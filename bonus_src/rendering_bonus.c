/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:25:42 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/29 02:22:25 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol.h"

void	my_pixel_put(t_img *image, int x, int y, int color)
{
	char	*img;

	img = image->addr + (y * image->llen + x * (image->bpp / 8));
	*(unsigned int *)img = color;
}

void	render(t_fract *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_check(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->connection,
		fractal->window, fractal->img.image, 0, 0);
}

t_cmpx	cmpx_sum(t_cmpx z, t_cmpx x)
{
	t_cmpx	res;

	res.r = z.r + x.r;
	res.i = z.i + x.i;
	return (res);
}
