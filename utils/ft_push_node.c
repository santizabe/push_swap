/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:34:39 by szapata-          #+#    #+#             */
/*   Updated: 2024/02/17 17:41:00 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_node(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	(*src)->next->prev = (*src)->prev;
	(*src)->prev->next = (*src)->next;
	*src = (*src)->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_lstadd_front(dst, tmp);
}
