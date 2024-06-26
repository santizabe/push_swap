/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:50:12 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 11:08:01 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstcopy(t_list *lst, int	*sorted, int lstsize)
{
	while (lstsize--)
	{
		*sorted = lst->num;
		sorted++;
		lst = lst->next;
	}
}

static void	ft_sort_arr(int	*sorted, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[i] > sorted[j])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	set_pos(t_list *lst, int *sorted, int lstsize)
{
	int	i;

	i = 0;
	while (i < lstsize)
	{
		while (1)
		{
			if (lst->num == sorted[i])
			{
				lst->pos = i + 1;
				lst->target = lst;
				break ;
			}
			lst = lst->next;
		}
		i++;
	}
}

int	sort_list(t_list *lst)
{
	int	lstsize;
	int	*sorted;

	lstsize = ft_lstsize(lst);
	sorted = (int *)malloc(lstsize * sizeof(int));
	if (!sorted)
	{
		ft_lstclear(&lst);
		return (0);
	}
	ft_lstcopy(lst, sorted, lstsize);
	ft_sort_arr(sorted, lstsize);
	set_pos(lst, sorted, lstsize);
	free(sorted);
	return (1);
}
