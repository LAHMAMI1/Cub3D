/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:54:35 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:20:58 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)) == 0)
		{
			i++;
		}
		else
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	}
	return (0);
}
