/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:20 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/29 15:01:03 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_num_str(char *str)
{
	char	*tmp;
	long	n;

	tmp = str;
	n = 0;
	if (str && (str[0] == '-' || str[0] == '+'))
		str++;
	while (str && *str)
		if (!ft_isdigit(*str++))
			return (0);
	n = ft_atoi(tmp);
	if (n < -2147483648 || n > 2147483647)
		return (0);
	return (1);
}

int	check_args(char **argv, int argc)
{
	int	tmp;

	tmp = argc;
	while (--tmp >= 0)
		if (!check_num_str(argv[tmp]))
			return (-1);
    while (--argc > 0)
    {
        tmp = argc;
        while (--tmp >= 0)
            if (!ft_strncmp(argv[argc], argv[tmp],
                ft_strlen(argv[argc])))
                return (-1);
    }
	return (0);
}
