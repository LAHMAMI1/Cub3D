/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:55:41 by fdiraa            #+#    #+#             */
/*   Updated: 2023/08/20 21:18:08 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counter(const char *s, char c)
{
	int	i;
	int	wrd;

	i = 0;
	wrd = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (i == 0 || s[i] == c)
		{
			while (s[i] == c)
			{
				i++;
			}
			if (s[i])
				wrd++;
			if (i == 0)
				i++;
		}
		else
			i++;
	}
	return (wrd);
}

char	*ft_dup(const char *s, int n)
{
	char	*dup;

	dup = malloc(sizeof(char) * (n + 1));
	ft_memcpy(dup, s, n);
	dup[n] = '\0';
	return (dup);
}

int	ft_free(char **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	h;
	unsigned int	w;
	int				i;
	char			**new_array;

	h = 0;
	w = 0;
	new_array = malloc((ft_counter(s, c) + 1) * sizeof(char *));
	if (!new_array || !s)
		return (NULL);
	i = -1;
	while (h <= ft_strlen(s))
	{
		if (s[h] != c && i < 0)
			i = h;
		else if ((s[h] == c || h == ft_strlen(s)) && i >= 0)
		{
			new_array[w++] = ft_dup((s + i), (h - i));
			i = -2;
		}
		h++;
	}
	new_array[w] = 0;
	return (new_array);
}
