/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 04:46:41 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 09:08:36 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_costs(t_list *b, t_list *a, int target, int *res)
{
	int	count;
	int	t_res[2];

	count = 0;
	while (b->num != target)
	{
		count++;
		b = b->next;
	}
	t_res[0] = count;
	t_res[1] = ft_lstsize(b) - count;
	if ((int)a->cost[0] < t_res[0])
		res[0] = t_res[0];
	if ((int)a->cost[1] < t_res[1])
		res[1] = t_res[1];
	a->cost[0] = -1;
	a->cost[1] = -1;
	if (res[0] < res[1])
		a->cost[0] = res[0];
	else
		a->cost[1] = res[1];
}

void	set_nodes_costs(t_list *a, t_list *b, int lstsize)
{
	int	count;
	int	closest[2];

	count = 0;
	while (count < lstsize)
	{
		a->cost[0] = count;
		a->cost[1] = lstsize - count;
		closest[0] = count;
		closest[1] = lstsize - count;
		set_target_costs(b, a, a->target, &closest);
		count++;
		a = a->next;
	}
}

void	calc_costs(t_list *a, t_list *b, int *mids, int *res)
{
	int	lstsize;
	int	count;

	lstsize = ft_lstsize(a);
	set_nodes_costs(a, b, lstsize);
	count = 0;
	while (count < lstsize)
	{
		if (a->cost[0] < a->cost[1] && a->cost[0] < res[0]
			&& a->cost[0] < res[1])
		{
			res[0] = a->cost[0];
			res[1] = a->cost[1];
			res[2] = count;
		}
		else if (a->cost[1] < a->cost[0] && a->cost[1] < res[1]
			&& a->cost[0] < res[0])
		{
			res[0] = a->cost[0];
			res[1] = a->cost[1];
			res[2] = count;
		}
		count++;
		a = a->next;
	}
}

void	calc_costs(t_list **a, t_list **b, int order)
{
	unsigned int	res[3];

	res[0] = -1;
	res[1] = -1;
	res[2] = -1;
	if (order == 1)
	{
		calc_cost(*a, *b, &res);
		exec_moves(a, b, &res, 1);
	}
	else if (order == 2)
	{
		calc_cost(*b, *a, &res);
		exec_moves(a, b, &res, 2);
	}
}
