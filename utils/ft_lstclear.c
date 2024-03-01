/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:35:08 by szapata-          #+#    #+#             */
/*   Updated: 2024/03/01 13:10:44 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp);
	}
	ft_lstdelone(*lst);
}
