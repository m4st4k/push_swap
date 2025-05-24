/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:08:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/24 12:06:40 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*stack_a(char **element, int *stack, size_t newlen, size_t oldlen)
{
	int		*new;
	size_t	i;

	i = 0;
	new = malloc((sizeof(int) * newlen));
	if (new == NULL)
		return (NULL);
	while ((stack != NULL) && (i < oldlen))
		new[i++] = *(stack++);
	free(stack - i);
	while (element != NULL && *element != NULL)
		new[i++] = ft_atoi(*(element++));
	return (new);
}

static	char	*ft_isvalidstring(char *str, size_t strlen)
{
	size_t	i;
	size_t	maxlen;

	i = 0;
	maxlen = strlen;
	if ((str == NULL) || (*str == '\0'))
		return (NULL);
	while (strlen && i < maxlen)
	{
		if (!ft_isdigit(str[i + 1]) && (str[i] == '-' || (str[i] == '+')))
			return (NULL);
		if ((str[i] == ' ') && !ft_isdigit(str[i + 1]))
			return (NULL);
		if (ft_isdigit(str[i + 1]) && (str[i] == '-' || (str[i] == '+')))
			i++;
		else if (!ft_isdigit(str[i]))
			return (NULL);
		i++;
		strlen--;
	}
	return (str);
}

static	char	**ft_checkelement(char *element, size_t *arrlen)
{
	size_t	b;
	char	**check;

	b = 0;
	check = ft_split(element, ' ');
	if (*check == NULL || check == NULL)
	{
		free(check);
		return (NULL);
	}
	while (check[b] != NULL)
	{
		if (ft_isvalidstring(check[b], ft_strlen(check[b])) == NULL)
		{
			b = 0;
			while (check[b] != NULL)
				free(check[b++]);
			free(check);
			return (NULL);
		}
		b++;
		(*arrlen)++;
	}
	return (check);
}

static	int	**ft_checkarguments(int arg, char ***argv, size_t *arrlen)
{
	size_t	arrlenold;
	char	**validelement;
	int		**stack_ab;
	int		*stack;

	stack = NULL;
	while (--arg)
	{
		arrlenold = *arrlen;
		validelement = ft_checkelement(**argv, arrlen);
		if (validelement == NULL)
			exit((printf("Error\n"), 0));
		stack = stack_a(validelement, stack, *arrlen, arrlenold);
		(*argv)++;
	}
	stack_ab = (int **)malloc(sizeof(int *) * 3);
	stack_ab[0] = stack;
	stack_ab[1] = malloc(sizeof(int) * (*arrlen));
	stack_ab[2] = NULL;
	return (stack_ab);
}

int	main(int arg, char *argv[])
{
	int	**stack;
	int	*stack_a;
	int	*stack_b;
	size_t	arrlen;

	arrlen = 0;
	stack = ft_checkarguments(arg, &(++argv), &arrlen);
	stack_a = stack[0];
	stack_b = stack[1];
	return (0);
}
