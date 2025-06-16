/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:31:40 by dbriant           #+#    #+#             */
/*   Updated: 2025/06/16 15:32:04 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	const	char	*parse_sign(const char *str, int *isneg)
{
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		*isneg = 1;
		str++;
	}
	return (str);
}

static	int	safe_add(int a, int b, int *overflow)
{
	if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a))
	{
		*overflow = 1;
		return (0);
	}
	return (a + b);
}

static	int	safe_mul(int a, int b, int *overflow)
{
	if ((a > INT_MAX / b) || (a < INT_MIN / b))
	{
		*overflow = 1;
		return (0);
	}
	return (a * b);
}

static	int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool	parse_integer(const char *nptr, int *array_a)
{
	int	overflow;
	int	num;
	int	digit;
	int	isneg;

	if (nptr == NULL)
		return (0);
	overflow = 0;
	num = 0;
	isneg = 0;
	nptr = parse_sign(nptr, &isneg);
	while (!overflow && is_digit(*nptr))
	{
		digit = (*nptr) - '0';
		if (isneg)
			digit = -digit;
		num = safe_mul(num, 10, &overflow);
		num = safe_add(num, digit, &overflow);
		nptr++;
	}
	if (overflow || *nptr != '\0')
		return (0);
	*array_a = num;
	return (1);
}
