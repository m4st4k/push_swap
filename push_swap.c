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
	char	*oldstr;

	i = 0;
	oldstr = str;
	if (*str == '-' || *str == '+')
		str++;
	strlen = ft_strlen(str);
	while (ft_isdigit(str[i]))
		i++;
	if (i < strlen)
		return (NULL);
	if (ft_atoi(oldstr) == 0)
		return (NULL);
	return (str);
}

static	int	get_arrlen(int arg, char *argv[])
{
	int		arrlen;
	char	*token_orig;
	char	*token_new;

	arrlen = 0;
	while (--arg)
	{
		token_orig = ft_strdup(*argv);
		token_new = get_next_token(token_orig, &arrlen);
		while (token_new != NULL)
		{
			if (ft_isvalidstring(token_new) == NULL)
				print_error(token_orig);
			arrlen++;
			token_new = get_next_token(NULL, &arrlen);
		}
		free(token_orig);
		argv++;
	}
	return (arrlen);
}

int	main(int arg, char *argv[])
{
	int	arrlen;
	int	i;
	int	*stack_a;
	//int	*stack_b;
	i = 0;
	arrlen = get_arrlen(arg, argv + 1);
	stack_a = create_a(arg, argv + 1, arrlen);
	check_dup_in_arr(stack_a, arrlen);
	//stack_b	= malloc(sizeof(int) * arrlen);
	printf("Size: %d\n", arrlen);
	while (i < arrlen)
		printf("Stack: %d\n", stack_a[i++]);
	free(stack_a);
	return (0);
}
