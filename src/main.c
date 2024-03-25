/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:52:57 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/25 20:18:42 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_dimensions(int dim, int i)
{
	if (i == 0 && (dim <= 0 || dim > 2560))
		return (0);
	if (i == 1 && (dim <= 0 || dim > 1440))
		return (0);
	return (1);
}

void	error(void)
{
	ft_putstr_fd(RED "Here are the available fractals:\n" RESET, 2);
	ft_putstr_fd("\t=> " GREEN "mandelbrot" RESET " <=\n\n", 2);
	ft_putstr_fd("\t=> " YELLOW "julia zr zi" RESET " <=\n\n", 2);
	ft_putstr_fd("\t=> " GREEN "burning_ship" RESET " <=\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fract	fractal;

	if (argc < 2)
		error();
	if (!check_dimensions(WIDTH, 0) || !check_dimensions(HEIGHT, 1))
	{
		ft_putstr_fd(RED "Invalid dimensions\n" RESET, 2);
		exit(EXIT_FAILURE);
	}
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.title = argv[1];
		if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = ft_atod(argv[2]);
			fractal.julia_y = ft_atod(argv[3]);
		}
		init(&fractal);
		render(&fractal);
		mlx_loop(fractal.connection);
	}
	else
		return (ft_putstr_fd("wrong usage of the program", 2), exit(EXIT_FAILURE), 1);
}
