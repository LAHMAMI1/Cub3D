/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:55:41 by fdiraa            #+#    #+#             */
/*   Updated: 2023/10/01 03:18:14 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **splited_array)
{
	char	**temp;

	temp = splited_array;
	if (splited_array == NULL)
		return ;
	while (*temp != NULL)
	{
		if (*temp != NULL)
			free(*temp);
		temp++;
	}
	free(splited_array);
}
