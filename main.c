/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:08:58 by szapata-          #+#    #+#             */
/*   Updated: 2024/03/01 13:29:45 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set_list(char **argv, int argc)
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	while (--argc > 0)
	{
		new = ft_lstnew(ft_atoi(argv[argc]));
		if (!new)
		{
			ft_lstclear(&head);
			return (NULL);
		}
		new->pos = 0;
		ft_lstadd_front(&head, new);
	}
	return (head);
}

int	check_num_str(char *str)
{
	if (str && str[0] == '-')
		str++;
	while (str && *str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int	check_args(char **argv, int argc)
{
	int	tmp;

	tmp = argc;
	while (--argc > 0)
		if (!check_num_str(argv[argc]))
			return (-1);
	if (tmp == 2)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*num_list;
	int		*sorted;

	if (argc == 1)
		return (0);
	if (check_args(argv, argc) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	num_list = set_list(argv, argc);
	if (!num_list)
		return (-1);
	sorted = sort_list(num_list);
	if (!sorted && free_all(1, num_list))
		return (-1);
	calculate_steps(num_list, sorted);
	free_all(2, sorted, num_list);
	return (0);
}
