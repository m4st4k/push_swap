/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_in_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:37:48 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/16 13:37:54 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	size_t	check_if_element_dup(int *arr, int element, size_t index)
{
	size_t	i;

	i = 0;
	while (index--)
	{
		if (arr[index] == element)
			i++;
	}
	return (i);
}

void	check_dup_in_arr(int *arr, size_t arrlen)
{
	size_t	i;
	size_t	count;

	i = 0;
	while (i < arrlen)
	{
		count = check_if_element_dup(arr, arr[i++], arrlen);
		if (count > 1)
			print_error(arr);
	}
}
