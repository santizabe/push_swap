/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:02:42 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/12 20:14:43 by szapata-         ###   ########.fr       */
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

	if (!ft_strlen(args))
		split = ft_split("0 0", ' ');
	else
		split = ft_split(args, ' ');
	if (!split)
		return (NULL);
	*argc = count_args(split) + 1;
	return (split);
}
