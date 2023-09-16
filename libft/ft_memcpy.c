/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:54:45 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:22:06 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*ds;
	unsigned char	*sc;

	i = 0;
	ds = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		ds[i] = sc[i];
		i++;
	}
	return (dest);
}
