/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:02:59 by fdiraa            #+#    #+#             */
/*   Updated: 2023/08/20 16:03:08 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (!number)
		return (0);
	if (number[i] == '-' && number[i + 1])
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}
