/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:57:56 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/16 14:18:45 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	size_t	str_len(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s++) != '\0')
		count++;
	return (count);
}

char	*str_dup(const char *s)
{
	char		*ptr;
	size_t		length;

	length = str_len(s);
	ptr = malloc((sizeof(char) * length) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[length] = '\0';
	while (length--)
		ptr[length] = s[length];
	return (ptr);
}
