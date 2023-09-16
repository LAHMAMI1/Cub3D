/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:00 by fdiraa            #+#    #+#             */
/*   Updated: 2023/08/20 22:23:58 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_memcpy((new + ft_strlen(s1)), s2, ft_strlen(s2));
	*(new + (ft_strlen(s1) + ft_strlen(s2))) = '\0';
	return (new);
}
