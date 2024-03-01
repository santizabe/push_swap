/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate_rev_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:45:43 by szapata-          #+#    #+#             */
/*   Updated: 2024/02/17 17:46:36 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstrotate_rev_two(t_list **lst_a, t_list **lst_b)
{
	ft_lstrotate_rev(lst_a);
	ft_lstrotate_rev(lst_b);
}
