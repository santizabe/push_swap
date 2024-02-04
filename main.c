/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:08:58 by szapata-          #+#    #+#             */
/*   Updated: 2024/02/04 16:28:33 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	count;
	
	count = 0;
	while (--argc > 0)
		if (!check_num_str(argv[argc]))
			return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (check_args(argv, argc) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}