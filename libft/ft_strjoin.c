/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:00 by fdiraa            #+#    #+#             */
/*   Updated: 2023/09/22 01:07:47 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
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
	free(s1);
	return (new);
}
