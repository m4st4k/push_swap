/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:38:17 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/16 13:38:20 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_white_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

char	*get_next_token(char *str)
{
	char		*token;
	static char	*str_current;

	if (str != NULL)
		str_current = str;
	while (is_white_space(*str_current))
		++str_current;
	if (*str_current == '\0')
		return (NULL);
	token = str_current;
	while (*str_current != '\0')
	{
		if (is_white_space(*str_current))
		{
			*(str_current++) = '\0';
			break ;
		}
		++str_current;
	}
	return (token);
}
