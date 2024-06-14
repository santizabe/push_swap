/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:14:06 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/13 14:10:54 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	exec_line(char *buffer, t_list **a, t_list **b)
{
	if (!ft_strncmp("pb\n", buffer, 3))
		ft_push_node(a, b);
	else if (!ft_strncmp("pa\n", buffer, 3))
		ft_push_node(b, a);
	else if (!ft_strncmp("ra\n", buffer, 3))
		ft_lstrotate(a);
	else if (!ft_strncmp("rb\n", buffer, 3))
		ft_lstrotate(b);
	else if (!ft_strncmp("rr\n", buffer, 3))
		ft_lstrotate_two(a, b);
	else if (!ft_strncmp("sa\n", buffer, 3))
		ft_swap(a);
	else if (!ft_strncmp("sb\n", buffer, 3))
		ft_swap(b);
	else if (!ft_strncmp("ss\n", buffer, 3))
		ft_swap_two(a, b);
	else if (!ft_strncmp("rra\n", buffer, 4))
		ft_lstrotate_rev(a);
	else if (!ft_strncmp("rrb\n", buffer, 4))
		ft_lstrotate_rev(b);
	else if (!ft_strncmp("rrr\n", buffer, 4))
		ft_lstrotate_rev_two(a, b);
	else
		return (-1);
	return (0);
}

static int	read_line(char *buffer, int *err)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		count = read(0, &buffer[i], 1);
		if (count < 0 && ++(*err))
			return (0);
		else if (count == 0)
			return (0);
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	return (1);
}

void	read_instructions(t_list *a, int *sorted_list)
{
	char	*buffer;
	int		err;
	t_list	*b;

	b = NULL;
	err = 0;
	buffer = (char *)malloc(4 * sizeof(char));
	if (!buffer)
		write(2, "Error\n", 6);
	else
		while (read_line(buffer, &err))
			if (exec_line(buffer, &a, &b) == -1 && ++err)
				break ;
	if (err)
		write(2, "Error\n", 6);
	else
	{
		if (!ft_issorted(a, 1) || ft_lstsize(b))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	free(buffer);
	free(sorted_list);
	ft_lstclear(&a);
}
