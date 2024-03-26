/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:52:57 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/26 21:46:05 by mbenchel         ###   ########.fr       */
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

void	routine(t_fract *fractal)
{
	init(fractal);
	render(fractal);
	mlx_loop(fractal->connection);
}

void	error(void)
{
	ft_putstr_fd(RED "Here are the available fractals:\n" RESET, 2);
	ft_putstr_fd("\t=> " GREEN "./fractol mandelbrot" RESET " <=\n\n", 2);
	ft_putstr_fd("\t=> " YELLOW "./fractol julia zr zi" RESET " <=\n\n", 2);
	ft_putstr_fd("\t=> " GREEN "./fractol tricorn" RESET " <=\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fract	fractal;

	if (argc < 2)
		error();
	if (!check_dimensions(WIDTH, 0) || !check_dimensions(HEIGHT, 1))
		return (ft_putstr_fd("Invalid dimensions", 2), exit(EXIT_FAILURE), 1);
	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot")))
	{
		fractal.title = argv[1];
		routine(&fractal);
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "julia"))
	{
		fractal.title = argv[1];
		fractal.julia_x = ft_atod(argv[2]);
		fractal.julia_y = ft_atod(argv[3]);
		routine(&fractal);
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "tricorn"))
	{
		fractal.title = argv[1];
		routine(&fractal);
	}
	else
		error();
}
