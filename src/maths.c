/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:21:37 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/21 03:44:36 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_cmpx	cmpx_sum(t_cmpx z, t_cmpx x)
{
	t_cmpx	res;

	res.r = z.r + x.r;
	res.i = z.i + x.i;
	return (res);
}

t_cmpx	cmpx_pow(t_cmpx z)
{
	t_cmpx	res;

	res.r = (z.r * z.r) - (z.i * z.i);
	res.i = 2 * z.r * z.i;
	return (res);
}

t_cmpx	total(t_cmpx z, t_cmpx c)
{
	t_cmpx	z_2;
	t_cmpx	z_2_c;

	z_2 = cmpx_pow(z);
	z_2_c = cmpx_sum(z_2, c);
	return (z_2_c);
}

double	atof(char *s)
{
	int		i;
	long	before_comma;
	double	after_comma;
	double	power;
	int		sign;

	before_comma = 0;
	after_comma = 0;
	sign = 1;
	power = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] != '.' && s[i])
	{
		before_comma = before_comma * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i])
	{
		power /= 10;
		after_comma = after_comma + (s[i++] - '0') * power;
	}
	return ((before_comma + after_comma) * sign);
}
