/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:30 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:41:19 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *f, int c)
{
	int	i;

	i = ft_strlen(f);
	if (((char)c) == 0)
	{
		return ((char *)(f + ft_strlen(f)));
	}
	while (i--)
	{
		if (f[i] == (char)c)
		{
			return ((char *)(f + i));
		}
	}
	return (NULL);
}
