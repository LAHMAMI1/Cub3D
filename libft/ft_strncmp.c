/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:20 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:38:54 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && *(str2 + i) && *(str1 + i))
	{
		if ((*(str1 + i) - *(str2 + i)) == 0)
		{
			i++;
		}
		else
			return (*(str1 + i) - *(str2 + i));
	}
	if (i == n)
		i--;
	return ((*(str1 + i) - *(str2 + i)));
}
