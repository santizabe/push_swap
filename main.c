/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:08:58 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/29 14:36:34 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*set_list(char **argv, int argc)
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

void	free_split(char **argv)
{
	while (*argv)
	{
		free(*argv);
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*num_list;
	int		split;
	int		*sorted;

	split = 0;
	if (argv++ && argc == 1)
		return (0);
	else if (argc == 2 && ++split)
		argv = ft_split_nums(&argc, *argv);
	if (check_args(argv, argc - 1) && write(2, "Error\n", 6))
		return (-1);
	num_list = set_list(argv, argc);
	if (!num_list)
		return (-1);
	sorted = sort_list(num_list);
	if (sorted)
		calculate_steps(num_list, sorted);
	if (split)
		free_split(argv);
	return (0);
}
