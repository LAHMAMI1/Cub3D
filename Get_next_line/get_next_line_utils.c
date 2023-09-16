/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:49:11 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/15 21:54:02 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_n(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen_n(s1, '\0') + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strchr_gnl(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return (i);
		i++;
	}
	if ((char)c == 0)
		return (i);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	p = malloc(ft_strlen_n(s1, '\0') + ft_strlen_n(s2, '\0') + 1);
	if (!p)
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}
