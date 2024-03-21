/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:36:00 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/21 03:14:49 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int close_window(t_fract *fractal)
{
	mlx_destroy_image(fractal->connection, fractal->img.image);
	mlx_destroy_window(fractal->connection, fractal->window);
	exit(0);
}
int	mouse_press(int button, int x, int y, t_fract *fractal)
{
	if (button == ZOOM_IN_MOUSE)
		fractal->zoom /= 1.05;
	else if (button == ZOOM_OUT_MOUSE)
		fractal->zoom *= 1.05;
	render(fractal);
	return (0);
}
int	key_press(int keycode, t_fract *fractal)
{
	if (keycode == ESC)
		close_window(fractal);
	else if (keycode == LEFT)
		fractal->shift_x -= (0.15 * fractal->zoom);//mvt stays proportional to zoom
	else if (keycode == RIGHT)
		fractal->shift_x += (0.15 * fractal->zoom);
	else if (keycode == UP)
		fractal->shift_y += (0.15 * fractal->zoom);
	else if (keycode == DOWN)
		fractal->shift_y -= (0.15 * fractal->zoom);
	else if (keycode == PLUS)
		fractal->iter_max += 10;
	else if (keycode == MINUS)
		fractal->iter_max -= 10;
	render(fractal);
	return (0);
}
