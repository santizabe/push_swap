/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:19 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 05:02:21 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost_a_b(t_list *min)
{
	int	count;

	count = min->t_cost[1];
	if (min->t_cost[0] == 2)
	{
		count = min->cost[0];
		if (min->target->cost[0] < min->cost[0])
			count = min->target->cost[0];
		min->cost[0] -= count;
		min->target->cost[0] -= count;
	}
	else
	{
		count = min->cost[1];
		if (min->target->cost[1] < min->cost[1])
			count = min->target->cost[1];
		min->cost[1] -= count;
		min->target->cost[1] -= count;
	}
	return (count);
}

void    exec_a_b_ext(t_list **a, t_list **b, t_list *min)
{
	if (min->t_cost[0] == 2)
	{
		while (min->cost[0]-- && write(1, "ra\n", 3))
			ft_lstrotate(a);
		while (min->target->cost[0]-- && write(1, "rb\n", 3))
			ft_lstrotate(b);
		if (!min->cost[0] && !min->target->cost[0]
			&& write(1, "pb\n", 3))
			ft_push_node(a, b);
	}
	else if (min->t_cost[0] == 3)
	{
		while (min->cost[1]-- && write(1, "rra\n", 4))
			ft_lstrotate_rev(a);
		while (min->target->cost[1]-- && write(1, "rrb\n", 4))
			ft_lstrotate_rev(b);
		if (!min->cost[1] && !min->target->cost[1]
			&& write(1, "pb\n", 3))
			ft_push_node(a, b);
	}
}

void    exec_b_a_ext(t_list **b, t_list **a, t_list *min)
{
	if (min->t_cost[0] == 2)
	{
		while (min->cost[0]-- && write(1, "rb\n", 3))
			ft_lstrotate(b);
		while (min->target->cost[0]-- && write(1, "ra\n", 3))
			ft_lstrotate(a);
		if (!min->cost[0] && !min->target->cost[0]
			&& write(1, "pa\n", 3))
			ft_push_node(b, a);
	}
	else if (min->t_cost[0] == 3)
	{
		while (min->cost[1]-- && write(1, "rrb\n", 4))
			ft_lstrotate_rev(b);
		while (min->target->cost[1]-- && write(1, "rra\n", 4))
			ft_lstrotate_rev(a);
		if (!min->cost[1] && !min->target->cost[1]
			&& write(1, "pa\n", 3))
			ft_push_node(b, a);
	}
}