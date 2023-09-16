/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:56:34 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:42:15 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	f_trim;
	size_t	l_trim;

	f_trim = 0;
	l_trim = ft_strlen(s1);
	while (*(s1 + f_trim) && ft_strchr(set, *(s1 + f_trim)))
	{
		f_trim++;
	}
	while (l_trim && ft_strchr(set, *(s1 + l_trim)))
	{
		l_trim--;
	}
	return (ft_substr(s1, f_trim, (l_trim - f_trim + 1)));
}
