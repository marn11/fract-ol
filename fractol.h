/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:34:22 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/13 02:49:04 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "utils/utils.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*image; // img struct pointer
	char	*pixels; // actual pixels pointer
	int		bpp;
	int		endian;
	int		llen;
}	t_img;
typedef struct s_fract
{
	char	*title;
	void	*connection; //mlx init
	void	*window; // mlx_new_window
	t_img	img;
}	t_fract;

void	init(t_fract *fractal);
void	render(t_fract *fractal);
double	scaling(double unscaled, double new_min, double new_max, double old_min, double old_max);

#endif
