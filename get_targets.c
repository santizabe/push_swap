/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:24:19 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 04:08:23 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    get_target_b(t_list *b, t_list *a)
{
    int lstsize;
    int min;
    int tmp_tgt;

    lstsize = ft_lstsize(a);
    min = a->num;
    tmp_tgt = b->target;
    while (lstsize--)
    {
        if (a->num < min)
            min = b->num;
        if (a->num < b->target && a->num > b->num)
            b->target = a->num;
        a = a->next;
    }
    if (b->target == tmp_tgt)
        b->target = min;
}

void    get_target_a(t_list *a, t_list *b)
{
    int lstsize;
    int max;
    int tmp_tgt;

    lstsize = ft_lstsize(b);
    max = b->num;
    tmp_tgt = a->target;
    while (lstsize--)
    {
        if (b->num > max)
            max = b->num;
        if (b->num > a->target && b->num < a->num)
            a->target = b->num;
        b = b->next;
    }
    if (a->target == tmp_tgt)
        a->target = max;
}

void    calc_targets(t_list *a, t_list *b, int order)
{
    int lstsize;

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
