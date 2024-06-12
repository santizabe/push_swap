/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:34:39 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 17:51:57 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_node(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	if ((*src)->next)
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		if ((*src)->next == (*src)->prev)
		{
			(*src)->next->next = NULL;
			(*src)->next->prev = NULL;
		}
	}
	*src = (*src)->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(dst, tmp);
}
