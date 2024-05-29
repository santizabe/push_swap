/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:33:53 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/29 14:36:52 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_mid(t_list **a, t_list **b, int mid, int lstsize)
{
	while (lstsize-- && !ft_issorted(*a, 1))
	{
		if ((*a)->num < mid)
		{
			ft_push_node(a, b);
			ft_putstr_fd("pb\n", 1);
		}
		else if ((*a)->prev->num < mid)
		{
			ft_lstrotate_rev(a);
			ft_putstr_fd("rra\n", 1);
		}
		else if ((*a)->next->num < mid)
		{
			ft_swap(a);
			ft_putstr_fd("sa\n", 1);
		}
		else
			break ;
	}
}

void	calculate_steps(t_list *a, int *sorted_list)
{
	write(1, "OK\n", 3);
	free(sorted_list);
	ft_lstclear(&a);
}

// if a->last < a->start & b->last > b->start --> rrr 