/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:33:53 by szapata-          #+#    #+#             */
/*   Updated: 2024/03/01 14:19:11 by szapata-         ###   ########.fr       */
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
	int		mid;
	int		lstsize;
	t_list	*b;

	lstsize = ft_lstsize(a);
	if (lstsize == 1 || check_sorted(a, lstsize))
		return ;
	mid = sorted_list[(lstsize / 2) + 1];
	compare_mid(&a, &b, mid, lstsize);
}

// if a->last < a->start & b->last > b->start --> rrr 