/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:08:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/26 05:23:08 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*stack_a(char **element, int *stack, size_t newlen, size_t oldlen)
{
	int		*new;
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	new = malloc((sizeof(int) * newlen));
	if (new == NULL || element == NULL)
		return (NULL);
	while (i < oldlen)
		new[i++] = *(stack++);
	while (element[b] != NULL)
		new[i++] = ft_atoi(element[b++]);
	while (*element != NULL)
		free(*(element++));
	free(stack - oldlen);
	return (new);
}

static	char	*ft_isvalidstring(char *str)
{
	size_t	i;
	size_t	strlen;
	ssize_t	val;

	i = 0;
	strlen = ft_strlen(str);
	val = ft_atoi(str);
	while (i < strlen)
	{
		if (str[i] == ' ')
			i++;
		if ((str[i] == '-') || (str[i] == '+'))
			i++;
		if (ft_isdigit(str[i]) && (ft_isdigit(str[i + 1])
				|| (str[i + 1] == ' ') || (str[i + 1] == '\0')))
			i++;
		else
			return (NULL);
		if (val > 4294967295 || val < -2147483648)
			return (NULL);
	}
	return (str);
}

static	char	**ft_checkelement(char *element, size_t *arrlen)
{
	size_t	b;
	char	**check;

	b = 0;
	check = ft_split(element, ' ');
	if (check == NULL)
		return (NULL);
	while (check[b] != NULL)
	{
		if (ft_isvalidstring(check[b]) == NULL)
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

static	int	*ft_checkarguments(int arg, char *argv[], size_t *arrlen)
{
	size_t	arrlenold;
	char	**validstring;
	int		*stack;

	stack = NULL;
	while (--arg)
	{
		arrlenold = *arrlen;
		validstring = ft_checkelement(*argv, arrlen);
		stack = stack_a(validstring, stack, *arrlen, arrlenold);
		if (stack == NULL || validstring == NULL)
			exit((printf("Error\n"), 0));
		argv++;
	}
	return (stack);
}

int	main(int arg, char *argv[])
{
	int	*stack_a;
	size_t	arrlen;

	arrlen = 0;
	stack_a = ft_checkarguments(arg, argv + 1, &arrlen);
	size_t i = 0;
	while (i < arrlen)
	{
		printf("Index: %ld, Val: %d\n", i, stack_a[i]);
		i++;
	}

	return (0);
}
