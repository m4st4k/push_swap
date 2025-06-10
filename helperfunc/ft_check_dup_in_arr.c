/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup_in_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:16:16 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/09 23:42:48 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	check_if_element_dup(int *arr, int element, size_t index)
{
	size_t	i;

	i = 0;
	while (index--)
	{
		if (arr[index] == element)
			i++;
		if (i == 2)
			return (1);
	}
	return (0);
}

void	check_dup_in_arr(int *arr, size_t arrlen)
{
	size_t	i;

	i = 0;
	while (i < arrlen)
	{
		if (chech_if_element_dup(arr, arr[i++], arrlen) == 1)
			print_error(arr);
	}
}
