/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:55:05 by szapata-          #+#    #+#             */
/*   Updated: 2024/02/17 17:30:49 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->prev;
	if ((*lst)->next != (*lst)->prev)
	{
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->next->prev = *lst;
		(*lst)->next->next = *lst;
		(*lst)->next->prev = (*lst)->prev;
		(*lst)->prev = (*lst)->next;
		(*lst)->next = tmp;
	}
	*lst = (*lst)->prev;
}
