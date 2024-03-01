/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:10:06 by szapata-          #+#    #+#             */
/*   Updated: 2024/03/01 13:34:03 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

int	free_all(int n, ...)
{
	va_list	ap;

	va_start(ap, n);
	while (n--)
		free(va_arg(ap, void *));
	va_end(ap);
	return (1);
}
