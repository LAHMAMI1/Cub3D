/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:55:00 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:23:05 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*temp;

	if (src == dest)
		return (dest);
	i = n;
	temp = (unsigned char *)src;
	if ((!dest || !src) && n == 0x0)
		return (NULL);
	if (src < dest)
	{
		while (i--)
		{
			*(unsigned char *)(dest + i) = temp[i];
		}
	}
	else
		ft_memcpy(dest, temp, n);
	return (dest);
}
