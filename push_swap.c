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
	int		*array_a;
	char	*token;
	size_t	i;

	i = 0;
	array_a = malloc((sizeof(int) * newlen));
	while (--arg)
	{
		token = get_next_token(*argv);
		while (token != NULL)
		{
			if (parse_integer(token, &(array_a[i++])) == 0)
				print_error(array_a);
			token = get_next_token(NULL);
		}
		++argv;
	}
	
	return (array_a);
}

static	int	get_arrlen(int arg, char *argv[])
{
	int		arrlen;
	char	*str_copy;

	arrlen = 0;
	while (--arg)
	{
		str_copy = str_dup(*argv);
		get_next_token(str_copy);
		++arrlen;
		while (get_next_token(NULL) != NULL)
			++arrlen;
		free(str_copy);
		++argv;
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
