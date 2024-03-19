/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:31:55 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/18 21:03:50 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void my_pixel_put(t_img *fract, int x, int y, int color)
{
	char	*img;

	img = fract->addr + (y * fract->llen + x * (fract->bpp / 8));
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
