/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:52:57 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/18 20:53:39 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fract	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.title = argv[1];
		init(&fractal);
		render(&fractal);
		mlx_loop(fractal.connection);
	}
	else
		return (perror("wrong usage of the program"), exit(EXIT_FAILURE), 1);
}
