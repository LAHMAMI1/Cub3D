/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiraa <fdiraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:19:34 by fdiraa            #+#    #+#             */
/*   Updated: 2022/10/27 22:15:22 by fdiraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst)
	{
		temp = *lst;
		while (*lst)
		{
			temp = temp->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
	}
}
