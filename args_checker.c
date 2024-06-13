/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:20 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 20:29:59 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **argv)
{
	char	**tmp;

	tmp = argv;
	while (*argv)
	{
		free(*argv);
		argv++;
	}
	free(tmp);
}

static int	check_num_str(char *str)
{
	char	*tmp;
	long	n;

	tmp = str;
	n = 0;
	if (str && (str[0] == '-' || str[0] == '+'))
		str++;
	if (!*str)
		return (0);
	while (str && *str)
		if (!ft_isdigit(*str++))
			return (0);
	n = ft_atol(tmp);
	if (n < -2147483648 || n > 2147483647)
		return (0);
	return (1);
}

int	compare_str(char **argv, int argc, int tmp)
{
	while (--tmp >= 0)
		if (ft_atoi(argv[argc]) == ft_atoi(argv[tmp]))
			return (-1);
	return (0);
}

int	check_args(char **argv, int argc, int split)
{
	int	tmp;

	tmp = argc;
	while (--tmp >= 0)
	{
		if (!check_num_str(argv[tmp]))
		{
			if (split)
				free_split(argv);
			return (-1);
		}
	}
	while (--argc > 0)
	{
		tmp = argc;
		if (compare_str(argv, argc, tmp) == -1)
		{
			if (split)
				free_split(argv);
			return (-1);
		}
	}
	return (0);
}
