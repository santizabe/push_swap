/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:02:42 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/29 14:45:41 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **split)
{
	int	i;

	i = 0;
	while (*split && ++i)
		split++;
	return (i);
}

char	**ft_split_nums(int *argc, char *args)
{
	char	**split;

	split = ft_split(args, ' ');
	if (!split)
		return (NULL);
	*argc = count_args(split) + 1;
	return (split);
}
