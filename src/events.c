/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:36:00 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/29 02:05:52 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(t_fract *fractal)
{
	mlx_destroy_image(fractal->connection, fractal->img.image);
	mlx_destroy_window(fractal->connection, fractal->window);
	exit(0);
}

int	mouse_press(int button, int x, int y, t_fract *fractal)
{
	(void)x;
	(void)y;
	if (button == ZOOM_IN_MOUSE || button == ZOOM_OUT_MOUSE)
	{
		if (button == ZOOM_IN_MOUSE)
			fractal->zoom *= 0.9;
		else
			fractal->zoom *= 1.1;
		render(fractal);
	}
	return (0);
}

int	key_press(int keycode, t_fract *fractal)
{
	if (keycode == ESC)
		close_window(fractal);
	else if (keycode == PLUS)
		fractal->iter_max += 10;
	else if (keycode == MINUS)
		fractal->iter_max -= 10;
	else if (keycode == ENTER)
		values(fractal);
	render(fractal);
	return (0);
}
