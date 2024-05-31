/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:33:53 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 10:07:21 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets(t_list *lst, int num)
{
	t_list	*tmp;
	int		lstsize;

	if (!lst)
		return ;
	lstsize = ft_lstsize(lst);
	tmp = lst;
	while (tmp->num != num)
		tmp = tmp->next;
	while (lstsize--)
	{
		lst->target = tmp;
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

void	calculate_steps(t_list *a, int *sorted_list)
{
	t_list	*b;
	int		lstsize;

	lstsize = ft_lstsize(a);
	b = NULL;
	set_targets(a, sorted_list[0]);
	while (ft_lstsize(a) > 3)
		calc_move(&a, &b, 1);
	sort_three(&a);
	set_targets(b, sorted_list[lstsize - 1]);
	while(ft_lstsize(b))
		calc_move(&a, &b, 2);
	free(sorted_list);
	ft_lstclear(&a);
}
