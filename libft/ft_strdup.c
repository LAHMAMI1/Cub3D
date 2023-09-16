/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:55:50 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:31:58 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	n;

	n = ft_strlen(s) + 1;
	new = (char *)malloc(sizeof(char) * n);
	if (!new)
		return (0);
	ft_memcpy(new, s, n);
	return (new);
}
