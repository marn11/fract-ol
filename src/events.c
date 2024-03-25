/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:36:00 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/25 02:11:48 by mbenchel         ###   ########.fr       */
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
	t_cmpx	mouse;
	double	zoom;

	if (button == ZOOM_IN_MOUSE || button == ZOOM_OUT_MOUSE)
	{
		mouse.r = scale_coords(x, fractal->start_pos_x,
				fractal->end_pos_x, WIDTH - 1);
		mouse.i = scale_coords(y, fractal->start_pos_y,
				fractal->end_pos_y, HEIGHT - 1);
		if (button == ZOOM_IN_MOUSE)
			zoom = 0.9;
		else
			zoom = 1.1;
		fractal->zoom *= zoom;
		fractal->start_pos_x = (fractal->start_pos_x - mouse.r)
			* zoom + mouse.r;
		fractal->start_pos_y = (fractal->start_pos_y - mouse.i)
			* zoom + mouse.i;
		fractal->end_pos_x = (fractal->end_pos_x - mouse.r) * zoom + mouse.r;
		fractal->end_pos_y = (fractal->end_pos_y - mouse.i) * zoom + mouse.i;
		render(fractal);
	}
	return (0);
}

int	key_press(int keycode, t_fract *fractal)
{
	if (keycode == ESC)
		close_window(fractal);
	else if (keycode == LEFT)
		fractal->shift_x -= (0.15 * fractal->zoom);
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
	else if (keycode == ENTER)
		values(fractal);
	else if (keycode == SPACE)
		fractal->color += 1;
	render(fractal);
	return (0);
}
