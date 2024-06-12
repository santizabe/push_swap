/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 04:46:41 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 00:13:15 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_nodes_costs(t_list *lst)
{
	int	lstsize;
	int	count;

	lstsize = ft_lstsize(lst);
	count = 0;
	while (count < lstsize)
	{
		lst->cost[0] = count;
		lst->cost[1] = lstsize - count;
		count++;
		lst = lst->next;
	}
}

void	set_node_t_cost(t_list *a, int opt, int min)
{
	a->t_cost[0] = opt;
	a->t_cost[1] = min;
}

void	set_lower_cost(t_list *a, int *options)
{
	int	count;
	int	min;

	count = 0;
	min = options[count];
	while (count < 4)
		if (options[count++] < min)
			min = options[count - 1];
	if (min == options[0])
		set_node_t_cost(a, 0, min);
	else if (min == options[1])
		set_node_t_cost(a, 1, min);
	else if (min == options[2])
		set_node_t_cost(a, 2, min);
	else
		set_node_t_cost(a, 3, min);
}

void	calc_cost(t_list *a, t_list *b)
{
	int	a_size;
	int	options[4];

	set_nodes_costs(a);
	set_nodes_costs(b);
	a_size = ft_lstsize(a);
	while (a_size--)
	{
		options[0] = a->cost[0] + a->target->cost[1];
		options[1] = a->cost[1] + a->target->cost[0];
		options[2] = a->cost[0];
		options[3] = a->cost[1];
		if (a->target->cost[0] > a->cost[0])
			options[2] = a->target->cost[0];
		if (a->target->cost[1] > a->cost[1])
			options[3] = a->target->cost[1];
		set_lower_cost(a, options);
		a = a->next;
	}
}

void	calc_costs(t_list **a, t_list **b, int order)
{
	if (order == 1)
	{
		calc_cost(*a, *b);
		exec_moves(a, b, 1);
	}
	else if (order == 2)
	{
		calc_cost(*b, *a);
		exec_moves(a, b, 2);
	}
}
