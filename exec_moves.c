/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 07:39:28 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 11:06:43 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_info(t_list *a, unsigned int count, int *info)
{
    while (count--)
        a = a->next;
    info[0] = a->target->num;
    return (a->num);
}

void    exec_a(t_list **a, t_list **b, int *info)
{
    info[0] = (*a)->target->cost[0];
    info[1] = (*b)->target->cost[0];
}

void    exec_b(t_list **a, t_list **b, int *info)
{
    info[0] = (*a)->target->cost[0];
    info[1] = (*b)->target->cost[0];

}

void    exec_two(t_list **a, t_list **b, int *res)
{
    int info[3];

    info[1] = 0;
    info[2] = 0;
    if (res[1] < res[0])
        info[2] = 1;
    info[0] = get_info(*a, res[2], info);
    while (res[0] && res[1] && (*a)->num != info[0] && (*b)->num != info[1])
    {
        if (info[2] == 0 && write(1, "rr\n", 3))
            ft_lstrotate_two(a, b);
        else if (info[2] == 1 && write(1, "rrr\n", 4))
            ft_lstrotate_rev_two(a, b);
        res[0]--;
        res[1]--;
    }
}

void    exec_moves(t_list **a, t_list **b, int *res, int order)
{
    if (order == 1)
    {
        exec_two(a, b, res);
        exec_a(a, b, res);
        exec_b(a, b, res);
    }
    else if (order == 2)
    {
        exec_two(a, b, res);
        exec_a(a, b, res);
        exec_b(a, b, res);
    }
}