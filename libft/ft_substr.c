/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:38 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:43:22 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if ((size_t)start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !new)
		return (NULL);
	ft_memcpy(new, (s + start), len);
	new[len] = '\0';
	return (new);
}
