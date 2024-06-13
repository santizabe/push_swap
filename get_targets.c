/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:24:19 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 22:32:30 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_b(t_list *b, t_list *a)
{
	int		lstsize;
	t_list	*min;
	int		max;

	lstsize = ft_lstsize(a);
	min = a;
	max = a->num;
	while (lstsize--)
	{
		if (a->num < min->num)
			min = a;
		if (a->num <= b->target->num && a->num > b->num)
			b->target = a;
		if (a->num > max)
			max = a->num;
		a = a->next;
	}
	if (b->num > max)
		b->target = min;
}

void	get_target_a(t_list *a, t_list *b)
{
	int		lstsize;
	t_list	*max;
	int		min;

	lstsize = ft_lstsize(b);
	max = b;
	min = b->num;
	while (lstsize--)
	{
		if (b->num > max->num)
			max = b;
		if (b->num >= a->target->num && b->num < a->num)
			a->target = b;
		if (b->num < min)
			min = b->num;
		b = b->next;
	}
	if (a->num < min)
		a->target = max;
}

void	calc_targets(t_list *a, t_list *b, int order)
{
	int	lstsize;

	lstsize = 0;
	if (order == 1)
	{
		lstsize = ft_lstsize(a);
		while (lstsize--)
		{
			get_target_a(a, b);
			a = a->next;
		}
	}
	else if (order == 2)
	{
		lstsize = ft_lstsize(b);
		while (lstsize--)
		{
			get_target_b(b, a);
			b = b->next;
		}
	}
}
