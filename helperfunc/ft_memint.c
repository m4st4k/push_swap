/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 05:46:22 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/26 07:07:09 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_memint(const void *s, int c, size_t n)
{
	int		target;
	size_t	i;

	i = 0;
	target = c;
	while (n)
	{
		if (*(int *)s == target)
			i++;
		n--;
		s = (int *)s + 1;
	}
	return (i);
}
