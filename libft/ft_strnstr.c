/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:24 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/29 23:31:34 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *larg, const char *small, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	small_n;

	i = 0;
	small_n = ft_strlen(small);
	if (!larg && n == 0)
		return (NULL);
	if (!*small)
		return ((char *)larg);
	while (*(larg + i) && i < n)
	{
		j = 0;
		while (*(larg + i + j) == *(small + j) && i + j < n)
		{
			j++;
			if (j == small_n)
				return ((char *)(larg + i));
		}
		i++;
	}
	return (0);
}
