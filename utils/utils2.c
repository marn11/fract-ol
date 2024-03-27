/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:47:48 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/27 02:18:35 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_isd(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	part1(int *i, char *s)
{
	if (!ft_isd(s[*i]))
		return (0);
	while (s[*i] && ft_isd(s[*i]))
		(*i)++;
	if (s[*i] && s[*i] != '.')
		return (0);
	if (s[*i] && s[*i] == '.')
		(*i)++;
	return (1);
}

int	part2(int *i, char *s)
{
	if (!ft_isd(s[*i]))
		return (0);
	while (s[*i] && ft_isd(s[*i]))
		(*i)++;
	if (s[*i] && !ft_isd(s[*i]))
		return (0);
	return (1);
}

t_cmpx	cmpx_sum(t_cmpx z, t_cmpx x)
{
	t_cmpx	res;

	res.r = z.r + x.r;
	res.i = z.i + x.i;
	return (res);
}
