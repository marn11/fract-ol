/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:35:04 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/17 23:42:58 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	values(t_fract *fractal)
{

}
void	init(t_fract *fractal)
{
	fractal->connection = mlx_init();
	if (!fractal->connection)
		exit(1);
	fractal->window = mlx_new_window(fractal->connection,
			WIDTH, HEIGHT, fractal->title);
	if (!fractal->window)
		perror("Error");
		exit(1);
	fractal->img.image = mlx_new_image(fractal->connection,
			WIDTH, HEIGHT);
	if (!fractal->img.image)
	{
		mlx_destroy_window(fractal->connection, fractal->window);
		perror("malloc error");
		exit(1);
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.image, &fractal->img.bpp,
			&fractal->img.llen, &fractal->img.endian);
	//events_init(fractal);
	values(fractal);
}
