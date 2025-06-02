/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:08:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/02 21:08:10 by dbriant          ###   ########.fr       */
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
		free(cache);
		argv++;
	}
	return (new);
}

static	char	*ft_isvalidstring(char *str)
{
	size_t	i;
	size_t	strlen;
	char	*origstr;

	i = 0;
	origstr = str;
	if ((*str == '-') || (*str == '+'))
		str++;
	if (!ft_isdigit(str[i]))
		return (NULL);
	strlen = ft_strlen(str);
	while (ft_isdigit(str[i]))
		i++;
	if (i < strlen || i > 10)
		return (NULL);
	if (*str != '0')
	{
		if (ft_atoi(origstr) == 0)
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

static	void	*ft_memint(const int *s, int c, size_t n)
{
	size_t	i;
	size_t	b;

	b = 0;
	i = 0;
	while (n--)
	{
		if (s[i++] == c)
			b++;
		if (b > 1)
			return (NULL);
	}
	return ((int *)s);
}

int	main(int arg, char *argv[])
{
	int	arrlen;
	int	i;
	int	b;
	int	*stack_a;
	//int	*stack_b;

	i = 0;
	arrlen = get_arrlen(arg, argv + 1);
	stack_a = create_a(arg, argv + 1, arrlen);
	b = arrlen;
	//stack_b	= malloc(sizeof(int) * arrlen);
	while (b--)
	{
		if (ft_memint(stack_a, stack_a[b], arrlen) == NULL)
			exit((printf("Error\n"), 0));
	}
	printf("Size: %d\n", arrlen);
	while (i < arrlen)
		printf("Stack: %d\n", stack_a[i++]);
	free(stack_a);
	return (0);
}
