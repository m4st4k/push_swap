/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:25:06 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/10 02:04:40 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	char	*start_token(char *str)
{
	while ((*str == ' ') && (*str != '\0'))
		str++;
	if (*str == '\0')
		return (NULL);
	return (str);
}

static	char	*zero_terminate_token(char *token)
{
	new = str;
	while ((*str != ' ') && (*str != '\0'))
		str++;
	if (*token == ' ')
	{
	    *token = '\0';
	    token++;
	}
	return (token);
}

char	*get_next_token(char *str, int *arrlen)
{
	static char	*token;
	char	*new;

	if (str != NULL)
		token = str;
	token = start_token(token);
	if (token == NULL)
		return (NULL);
	new = token;
	token = zero_terminate_token(token);
	return (new);
}
