/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:33:53 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 22:38:26 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_max(t_list *a, t_list **min, t_list **max)
{
	int	lstsize;
	int	count;

	lstsize = ft_lstsize(a);
	count = 0;
	while (count < lstsize)
	{
		if (a->pos == 1)
			*min = a;
		else if ((int)a->pos == lstsize)
			*max = a;
		a = a->next;
		count++;
	}
}

void	set_targets(t_list *lst, t_list *tgt)
{
	int	lstsize;

	lstsize = ft_lstsize(lst);
	while (lstsize--)
	{
		lst->target = tgt;
		lst = lst->next;
	}
}

void	sort_three(t_list **a)
{
	int	lstsize;

	lstsize = ft_lstsize(*a);
	if (lstsize == 2 && !ft_issorted(*a, 1) && write(1, "sa\n", 3))
		ft_swap(a);
	while (!ft_issorted(*a, 1))
	{
		if ((*a)->num > (*a)->prev->num && (*a)->num > (*a)->next->num
			&& write(1, "ra\n", 3))
			ft_lstrotate(a);
		else if ((*a)->prev->num < (*a)->next->num && write(1, "rra\n", 4))
			ft_lstrotate_rev(a);
		else if ((*a)->num > (*a)->next->num && write(1, "sa\n", 3))
			ft_swap(a);
	}
}

void	calculate_steps(t_list *a)
{
	t_list	*b;
	t_list	*min;
	t_list	*max;

	b = NULL;
	min = NULL;
	max = NULL;
	set_min_max(a, &min, &max);
	while (ft_lstsize(a) > 3)
	{
		set_targets(a, min);
		calc_move(&a, &b, 1);
	}
	sort_three(&a);
	while (ft_lstsize(b))
	{
		set_targets(b, max);
		calc_move(&a, &b, 2);
	}
	order_list(&a);
}
