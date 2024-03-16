/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:38:08 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/16 17:43:19 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_coords(double pos, double cmp_min, double cmp_max, double w_max)
{
	return (cmp_max - cmp_min) * (pos)/ (w_max) + cmp_min;
}

