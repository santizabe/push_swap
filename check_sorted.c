/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:38:04 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/29 14:01:49 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_dist(int count, int lstsize)
{
	int	mid;

	if (count == 1)
		return (1);
	mid = lstsize / 2;
	if (lstsize % 2)
		mid = (lstsize / 2) + 1;
	if (count++ > mid)
	{
		while (count--)
			ft_putstr_fd("rra\n", 1);
	}
	else
	{
		while (count--)
			ft_putstr_fd("ra\n", 1);
	}
	return (1);
}

int	check_sorted(t_list *lst, int lstsize)
{
	int		count;

	count = 0;
	while (lstsize-- && ++count)
		if (lst->pos == 1)
			break ;
	if (ft_issorted(lst, 1))
		return (calc_dist(count, lstsize));
	return (0);
}
