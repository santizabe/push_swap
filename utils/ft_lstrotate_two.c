/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:43:36 by szapata-          #+#    #+#             */
/*   Updated: 2024/03/01 13:31:40 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstrotate_two(t_list **lst_a, t_list **lst_b)
{
	ft_lstrotate(lst_a);
	ft_lstrotate(lst_b);
}
