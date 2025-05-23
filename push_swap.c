/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:08:52 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/21 02:44:27 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_checkelement(char *element)
{
	size_t	i;
	char	**check;

	check = ft_split(element, ' ');
	while (*check != NULL)
	{
		if (!ft_isdigit(**))
	}
	printf("Final: %s\n", element);
}

static	void	ft_checkarguments(int arg, char ***argv)
{
	while (arg)
	{
		ft_checkelement(**argv);
		(*argv)++;
		arg--;
	}
}

int	main(int arg, char *argv[])
{
	int	newinput[--arg];

	argv++;
	ft_checkarguments(arg, &argv);
	while (arg)
		newinput[--arg] = ft_atoi(*argv++);
	printf("newinput: %d", *newinput);
	return (0);
}
