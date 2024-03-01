/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:01:57 by szapata-          #+#    #+#             */
/*   Updated: 2024/02/18 11:52:45 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*aux;

	if (!lst)
		return (0);
	aux = NULL;
	i = 1;
	if (lst->next)
		aux = lst->next;
	while (aux && aux != lst)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
