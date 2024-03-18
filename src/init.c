/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:35:04 by mbenchel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/18 20:53:11 by mbenchel         ###   ########.fr       */
=======
/*   Updated: 2024/03/17 23:43:04 by mbenchel         ###   ########.fr       */
>>>>>>> 70d26bcaea7fe6b3f65bc429fdf1588ff28a26b5
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	values(t_fract *fractal)
{
<<<<<<< HEAD
	fractal->iter_max = 42;
=======
	
>>>>>>> 70d26bcaea7fe6b3f65bc429fdf1588ff28a26b5
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
