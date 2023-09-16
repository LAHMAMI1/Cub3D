/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:24:38 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/29 23:26:32 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
			return (-1);
		if (res > 9223372036854775808ul && var == -1)
			return (0);
	}
	return ((int)res * var);
}
