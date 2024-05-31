/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:24:19 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 11:11:54 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_b(t_list *b, t_list *a)
{
	int		lstsize;
	t_list	*min;
	int		tmp_tgt;

	lstsize = ft_lstsize(a);
	min = a;
	tmp_tgt = b->target->num;
	while (lstsize--)
	{
		if (a->num < min->num)
			min = a;
		if (a->num < b->target->num && a->num > b->num)
			b->target = a;
		a = a->next;
	}
	if (b->target->num == tmp_tgt)
		b->target = min;
}

void	get_target_a(t_list *a, t_list *b)
{
	int		lstsize;
	t_list	*max;
	int		tmp_tgt;

	lstsize = ft_lstsize(b);
	max = b;
	tmp_tgt = a->target->num;
	while (lstsize--)
	{
		if (b->num > max->num)
			max = b;
		if (b->num > a->target->num && b->num < a->num)
			a->target = b;
		b = b->next;
	}
	if (a->target->num == tmp_tgt)
		a->target = max;
}

void    calc_targets(t_list *a, t_list *b, int order)
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
