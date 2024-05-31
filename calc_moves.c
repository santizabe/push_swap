/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 00:29:55 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 11:08:46 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    calc_asc(t_list **a, t_list **b)
{
    int size_b;

    size_b = ft_lstsize(*b);
    if (size_b < 2 && write(1, "pb\n", 3))
    {
        ft_push_node(a, b);
        return ;
    }
    calc_targets(*a, *b, 1);
    calc_costs(a, b, 1);
}

static void    calc_desc(t_list **a, t_list **b)
{
    calc_targets(*a, *b, 2);
    calc_costs(a, b, 2);
}

void    calc_move(t_list **a, t_list **b, char order)
{
    if (order == 1)
        calc_asc(a, b);
    else if (order == 2)
        calc_desc(a, b);
}