/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:50:03 by fdiraa            #+#    #+#             */
/*   Updated: 2023/08/20 16:03:53 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdio.h>

int	set_errno(int ret)
{
	errno = ERANGE;
	return (ret);
}

long	ft_long_atoi(const char *str)
{
	unsigned long	res;
	int				var;
	int				i;

	res = 0;
	i = 0;
	var = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		var = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > 9223372036854775807 && var == 1)
			return (set_errno(-1));
		if (res > 9223372036854775808ul && var == -1)
			return (set_errno(0));
	}
	return ((long)res * var);
}
