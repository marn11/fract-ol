/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:16:43 by mbenchel          #+#    #+#             */
/*   Updated: 2024/03/27 01:50:29 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		check(char *s);
int		ft_isd(char c);
int		part1(int *i, char *s);
int		part2(int *i, char *s);

#endif
