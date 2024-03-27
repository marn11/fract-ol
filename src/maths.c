/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:21:37 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/27 02:18:53 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

static int	atoip(const char *s, int i, int sign)
{
	unsigned long	nb;
	int				digc;

	nb = 0;
	digc = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		digc++;
		if (digc == 20)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		nb = nb * 10 + s[i++] - 48;
	}
	if (nb > LONG_MAX)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return ((int)(nb * sign));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] == 48)
		i++;
	result = atoip(nptr, i, sign);
	return (result);
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
	s++;
	while (*s != '.' && *s)
		before_comma = before_comma * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		power /= 10;
		after_comma = after_comma + (*s++ - '0') * power;
	}
	return ((before_comma + after_comma) * sign);
}
