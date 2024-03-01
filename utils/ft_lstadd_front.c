/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:02:41 by szapata-          #+#    #+#             */
/*   Updated: 2024/02/17 15:01:45 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	if ((*lst)->prev)
	{
		(*lst)->prev->next = new;
		new->prev = (*lst)->prev;
	}
	else
	{
		(*lst)->next = new;
		new->prev = *lst;
	}
	(*lst)->prev = new;
	*lst = new;
}
