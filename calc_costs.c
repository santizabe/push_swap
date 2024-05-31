/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 04:46:41 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 11:07:00 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_lower_cost(t_list *a, int *res, int *options)
{
	int	count;
	int	min;

	count = 0;
	min = options[count];
	while (count < 4)
		if (options[count] < options[min])
			min = count;
	if (min == 0)
	{
		res[0] = a->cost[0];
		res[1] = a->target->cost[1];
	}
	else if (min == 1)
	{
		res[0] = a->cost[1] * -1;
		res[1] = a->target->cost[0];
	}
	else if (min == 2)
		res[0] = options[2];
	else if (min == 3)
		res[1] = options[3];
}

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

void	calc_cost(t_list *a, t_list *b, int *res)
{
	int	count;
	int	a_size;
	int	b_size;
	int	options[4];

	set_nodes_costs(a);
	set_nodes_costs(b);
	count = 0;
	a_size = ft_lstsize(a);
	b_size = ft_lstsize(b);
	while (count < a_size)
	{
		options[0] = a->cost[0] + a->target->cost[1];
		options[1] = a->cost[1] + a->target->cost[0];
		options[2] = a->cost[0];
		options[3] = a->cost[1];
		if (a->target->cost[0] > a->cost[0])
			options[2] = a->target->cost[0];
		if (a->target->cost[1] > a->cost[1])
			options[3] = a->target->cost[1];
		res[2] = a->cost[0];
		set_lower_cost(a, res, options);
	}
}

void	calc_costs(t_list **a, t_list **b, int order)
{
	int	res[3];

	res[0] = -1000;
	res[1] = -1000;
	res[2] = -1000;
	if (order == 1)
	{
		calc_cost(*a, *b, res);
		exec_moves(a, b, res, 1);
	}
	else if (order == 2)
	{
		calc_cost(*b, *a, res);
		exec_moves(a, b, res, 2);
	}
}
