/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:55:41 by fdiraa            #+#    #+#             */
/*   Updated: 2023/08/20 15:59:30 by fdiraa           ###   ########.fr       */
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
