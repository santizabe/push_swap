/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:16:23 by szapata-          #+#    #+#             */
/*   Updated: 2024/02/12 21:36:58 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	new->next = *lst;
	if ((*lst)->prev)
	{
		(*lst)->prev->next = new;
		new->prev = (*lst)->prev;
	}
	else
		new->prev = *lst;
	(*lst)->prev = new;
}
