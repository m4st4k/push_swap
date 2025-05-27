/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:25:06 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/27 12:05:09 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	char	*create_token(char **token, int *arrlen)
{
	size_t	i;
	char    *new;

	i = 0;
	if (**token == '\0')
		return (NULL);
	if (arrlen != NULL)
		*arrlen = (*arrlen) + 1;
	while ((**token == ' ') && (**token != '\0'))
	    (*token)++;
	while (((*token)[i] != ' ') && ((*token)[i] != '\0'))
		i++;
	new = malloc((sizeof(char) * i) + 1);
	i = 0;
	while ((**token != ' ') && (**token != '\0'))
		new[i++] = *((*token)++);
	new[i] = '\0';
	if (**token == ' ')
	    *token = (*token) + 1;
	return (new);
}

char	*get_next_token(char *str, int *arrlen)
{
	static	char	*token;

	if (str == NULL)
		return (create_token(&(token), arrlen));
	else
		token = str;
    return (create_token(&(token), arrlen));
}
