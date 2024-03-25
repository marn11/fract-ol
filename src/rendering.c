/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:31:55 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/25 20:04:16 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_check(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->connection, fractal->window, fractal->img.image, 0, 0);
}
