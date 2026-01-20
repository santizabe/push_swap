/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:15:36 by szapata-          #+#    #+#             */
/*   Updated: 2026/01/20 13:12:03 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_order(t_list *a)
{
	int	count;

	count = 0;
	while (a->pos != 1 && ++count)
		a = a->next;
	return (count);
}

void	order_list(t_list **a)
{
	int	lstsize;
	int	count;

	lstsize = ft_lstsize(*a);
	if (lstsize == 1)
		return ;
	count = find_order(*a);
	if (count < lstsize / 2)
		while (count-- && write(1, "ra\n", 3))
			ft_lstrotate(a);
	else
		while (count++ < lstsize && write(1, "rra\n", 4))
			ft_lstrotate_rev(a);
}
