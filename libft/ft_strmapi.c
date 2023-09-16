/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:15 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:38:17 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	while (*(s + i))
	{
		*(new + i) = f(i, s[i]);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}
