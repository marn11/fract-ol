/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:34:22 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/16 17:43:29 by mbenchel         ###   ########.fr       */
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
typedef struct s_cmpx
{
	double r;
	double i;
}	t_cmpx;

typedef struct s_fract
{
	char	*title;
	void	*connection; //mlx init
	void	*window; // mlx_new_window
	t_img	img;
	t_cmpx	z;
	t_cmpx	c;
}	t_fract;

void	init(t_fract *fractal);
void	render(t_fract *fractal);
double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max);

#endif
