/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:38:08 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/13 02:48:35 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double scaling(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min;
}
// tldraw to understand
