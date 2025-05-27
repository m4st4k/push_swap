/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:08:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/27 18:46:22 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*create_a(int arg, char *argv[], int newlen)
{
	int		*new;
	char	*cache;
	size_t	i;

	i = 0;
	new = malloc((sizeof(int) * newlen));
	while (--arg)
	{
		cache = get_next_token(*argv, NULL);
		while (cache != NULL)
		{
			new[i++] = ft_atoi(cache);
			free(cache);
			cache = get_next_token(NULL, NULL);
		}
		argv++;
	}
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
		if ((str[i] == '-') || (str[i] == '+'))
			i++;
		if (ft_isdigit(str[i]) &&
			(ft_isdigit(str[i + 1]) || (str[i + 1] == '\0')))
			i++;
		else
			return (NULL);
		if (val > 4294967295 || val < -2147483648)
			return (NULL);
	}
	return (str);
}

static	int	get_arrlen(int arg, char *argv[])
{
	int	arrlen;
	char	*str;

	arrlen = 0;
	while (--arg)
	{
		str = get_next_token(*argv, &arrlen);
		while (str != NULL)
		{
			if (ft_isvalidstring(str) == NULL)
			{
				free(str);
				exit((printf("Error\n"), 0));
			}
			free(str);
			str = get_next_token(NULL, &arrlen);
		}
		free(str);
		argv++;
	}
	return (arrlen);
}

int	main(int arg, char *argv[])
{
	int	arrlen;
	int	*stack_a;

	arrlen = get_arrlen(arg, argv + 1);
	stack_a = create_a(arg, argv + 1, arrlen);
	printf("Size: %d\n", arrlen);
	while (arrlen)
	{
		printf("Stack: %d\n", *(stack_a++));
		arrlen--;
	}
	return (0);
}
