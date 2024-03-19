/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:36:00 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/19 22:43:37 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_press(int keycode, t_fract *fractal)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_image(fractal->connection, fractal->img.image);
		mlx_destroy_window(fractal->connection, fractal->window);
		exit(0);
	}
	else if (keycode == LEFT)
		fractal->shift_x -= 0.5;
	else if (keycode == RIGHT)
		fractal->shift_x += 0.5;
	else if (keycode == UP)
		fractal->shift_y -= 0.5;
	else if (keycode == DOWN)
		fractal->shift_y += 0.5;
	else if (keycode == PLUS)
		fractal->iter_max += 10;
	else if (keycode == MINUS)
		fractal->iter_max -= 10;
	render(fractal);
	return (0);
}
