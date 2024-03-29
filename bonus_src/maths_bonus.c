/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:25:15 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/29 02:22:15 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol.h"

t_cmpx	cmpx_pow(t_cmpx z, int is_tricorn)
{
	t_cmpx	res;

	if (is_tricorn)
	{
		res.r = (z.r * z.r) - (z.i * z.i);
		res.i = -2 * z.r * z.i;
	}
	else
	{
		res.r = (z.r * z.r) - (z.i * z.i);
		res.i = 2 * z.r * z.i;
	}
	return (res);
}

static void	help_atod(char *s, long *bf, long double *af, long double *p)
{
	*bf = 0;
	*af = 0;
	*p = 1;
	while (*s != '.' && *s)
		*bf = *bf * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		*p /= 10;
		*af = *af + (*s++ - '0') * *p;
	}
}

static void	setsign(char c, int *sign)
{
	if (c == '-' || c == '+')
		if (c == '-')
			*sign *= -1;
}

double	ft_atod(char *s)
{
	long			before_comma;
	long double		after_comma;
	long double		power;
	int				sign;

	before_comma = 0;
	after_comma = 0;
	sign = 1;
	power = 1;
	if (!check(s))
		error();
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	setsign(*s, &sign);
	if (*s == '-' || *s == '+')
		s++;
	help_atod(s, &before_comma, &after_comma, &power);
	return ((before_comma + after_comma) * sign);
}
