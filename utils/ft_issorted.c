/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:01:33 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/29 14:05:41 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @lst: the list to check
 * @order: 1 for ascending, 2 for descending
 * @return: 1 if sorted, else 0.
*/

int	calc_asc(t_list *lst, int lstsize)
{
	int	tmp;

	while (--lstsize)
	{
		tmp = lst->next->num;
		if (lst->num > tmp)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	calc_desc(t_list *lst, int lstsize)
{
	int	tmp;

	while (--lstsize)
	{
		tmp = lst->next->num;
		if (lst->num < tmp)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_issorted(t_list *lst, int order)
{
	int	lstsize;
	int	status;

	lstsize = ft_lstsize(lst);
	status = 0;
	if (!lst || lstsize == 1)
		return (1);
	if (order == 1)
		status = calc_asc(lst, lstsize);
	else if (order == 2)
		status = calc_desc(lst, lstsize);
	return (status);
}
