/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:54:08 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:10:41 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new_char;
	long	x;
	int		len;

	len = int_len(n);
	x = n;
	if (x < 0)
	{
		x *= -1;
		len++;
	}
	new_char = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_char)
		return (NULL);
	*(new_char + len) = '\0';
	while (len--)
	{
		*(new_char + len) = x % 10 + 48;
		x /= 10;
	}
	if (n < 0)
	{
		new_char[0] = '-';
	}
	return (new_char);
}
