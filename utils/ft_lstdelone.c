/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:09:15 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/29 14:32:26 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdelone(t_list *node)
{
	if (!node)
		return ;
	if (node->prev)
	{
		if (node->prev != node->next)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		else
		{
			node->prev->next = NULL;
			node->prev->prev = NULL;
		}
	}
	node->next = NULL;
	node->prev = NULL;
	free(node);
	node = NULL;
}
