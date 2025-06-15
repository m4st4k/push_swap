/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:25:06 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/14 00:03:52 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_white_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

char	*get_next_token(char *str)
{
	static char	*str_current;
	char		*token;

	if (str != NULL)
		str_current = str;
	while (*str_current != '\0' && is_white_space(*str_current))
		str_current++;
	if (*str_current == '\0')
		return (NULL);
	token = str_current;
	while (*str_current != '\0' && !is_white_space(*str_current))
		str_current++;
	if (is_white_space(*str_current))
	{
		*str_current = '\0';
		str_current++;
	}
	return (token);
}
