/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:16:31 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/26 21:45:51 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	check(char *s)
{
	int	i;
	int	f_point;

	i = 0;
	f_point = 0;
	if (!ft_strlen(s))
		return (1);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (1);
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (!f_point)
				f_point = 1;
			else
				return (1);
		}
		else if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
