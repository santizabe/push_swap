/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 07:39:28 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 16:14:46 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *get_cheapest_node(t_list *lst)
{
	int     lstsize;
	t_list  *min;

	lstsize = ft_lstsize(lst);
	min = lst;
	while (lstsize--)
	{
		if (lst->t_cost[1] < min->t_cost[1])
			min = lst;
		lst = lst->next;
	}
	return (min);
}

void    exec_a_b(t_list **a, t_list **b, t_list *min)
{
	if (min->t_cost[0] == 0)
	{
		while (min->cost[0] && min->cost[0]-- && write(1, "ra\n", 3))
			ft_lstrotate(a);
		while (min->target->cost[1] && min->target->cost[1]--
			&& write(1, "rrb\n", 4))
			ft_lstrotate_rev(b);
		if (!min->cost[0] && !min->target->cost[1]
			&& write(1, "pb\n", 3))
			ft_push_node(a, b);
	}
	else if (min->t_cost[0] == 1)
	{
		while (min->cost[1] && min->cost[1]-- && write(1, "rra\n", 4))
			ft_lstrotate_rev(a);
		while (min->target->cost[0] && min->target->cost[0]--
			&& write(1, "rb\n", 3))
			ft_lstrotate(b);
		if (!min->cost[1] && !min->target->cost[0]
			&& write(1, "pb\n", 3))
			ft_push_node(a, b);
	}
	else
		exec_a_b_ext(a, b, min);
}

void    exec_b_a(t_list **b, t_list **a, t_list *min)
{
	if (min->t_cost[0] == 0)
	{
		while (min->cost[0] && min->cost[0]-- && write(1, "rb\n", 3))
			ft_lstrotate(b);
		while (min->target->cost[1] && min->target->cost[1]--
			&& write(1, "rra\n", 4))
			ft_lstrotate_rev(a);
		if (!min->cost[0] && !min->target->cost[1]
			&& write(1, "pa\n", 3))
			ft_push_node(b, a);
	}
	else if (min->t_cost[0] == 1)
	{
		while (min->cost[1] && min->cost[1]-- && write(1, "rrb\n", 4))
			ft_lstrotate_rev(b);
		while (min->target->cost[0] && min->target->cost[0]--
			&& write(1, "ra\n", 3))
			ft_lstrotate(a);
		if (!min->cost[0] && !min->target->cost[1]
			&& write(1, "pa\n", 3))
			ft_push_node(b, a);
	}
	else
		exec_b_a_ext(b, a, min);
}

void    exec_two(t_list **a, t_list **b, t_list *min)
{
	int count;

	if (min->t_cost[0] == 0 || min->t_cost[0] == 1)
		return ;
	count = get_cost_a_b(min);
	if (min->t_cost[0] == 2)
		while (count-- && write(1, "rr\n", 3))
			ft_lstrotate_two(a, b);
	else if (min->t_cost[0] == 3)
		while (count-- && write(1, "rrr\n", 4))
			ft_lstrotate_rev_two(a, b);
}

void    exec_moves(t_list **a, t_list **b, int order)
{
	t_list *min;

	min = NULL;
	if (order == 1)
	{
		min = get_cheapest_node(*a);
		exec_two(a, b, min);
		exec_a_b(a, b, min);
	}
	else if (order == 2)
	{
		min = get_cheapest_node(*b);
		exec_two(a, b, min);
		exec_b_a(b, a, min);
	}
}