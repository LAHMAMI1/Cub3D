/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:40:19 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/29 11:52:45 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_n;
	size_t	src_n;
	size_t	i;

	i = 0;
	src_n = ft_strlen(src);
	if (!dest && n == 0)
		return (src_n);
	dest_n = ft_strlen(dest);
	if (n <= dest_n)
		return (src_n + n);
	while (*(src + i) && dest_n + i < n - 1)
	{
		dest[dest_n + i] = src[i];
		i++;
	}
	dest[dest_n + i] = '\0';
	return (dest_n + src_n);
}
