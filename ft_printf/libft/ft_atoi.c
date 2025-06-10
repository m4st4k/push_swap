/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:01:09 by dbriant           #+#    #+#             */
/*   Updated: 2025/01/03 09:59:16 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

static	const	char	*skip_white_space_chars(const char *str)
{
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
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

int	ft_atoi(const char *nptr)
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
	nptr = skip_white_space_chars(nptr);
	nptr = parse_sign(nptr, &isneg);
	while (ft_isdigit(*nptr) && !overflow)
	{
		digit = (*nptr) - '0';
		if (isneg)
			digit = -digit;
		num = safe_mul(num, 10, &overflow);
		num = safe_add(num, digit, &overflow);
		nptr++;
	}
	if (overflow)
		num = 0;
	return ((int)num);
}
