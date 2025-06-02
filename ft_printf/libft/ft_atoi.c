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

static	int	ft_isnegative(const char *neg)
{
	if (neg == NULL || *neg == '\0')
		return (0);
	if (*neg == '-')
		return (1);
	return (0);
}

static	char	*ft_ignoreprint(const char *neg)
{
	char	i;

	i = '\t';
	while (i <= '\r')
	{
		while (*neg == i || *neg == ' ')
		{
			neg++;
			i = '\t';
		}
		i++;
	}
	while ((*neg == '-') || (*neg == '+'))
	{
		if (ft_isdigit(*(neg + 1)))
			break ;
		neg++;
	}
	return ((char *)neg);
}

static	int	create_int_val(char *negativeint, size_t isneg)
{
	int	num;
	size_t	i;

	i = 0;
	num = 0;
	while (negativeint[i] != '\0')
	{
		if (i == 9 && isneg && negativeint[i] == '8')
			num = (((negativeint[i++] - '0') - 1) + (num * 10));
		else
			num = ((negativeint[i++] - '0') + (num * 10));
	}
	if (isneg && negativeint[i-1] == '8')
		num = (-num) - 1;
	else if (isneg)
		num = -num;
	return (num);
}

static	int	int_near_overflow(char *str, size_t isneg)
{
	char	*maxint;
	size_t	b;

	b = 0;
	if (isneg)
		maxint = "2147483648";
	else
		maxint = "2147483647";
	while (ft_isdigit(maxint[b]))
	{
		if (str[b] > maxint[b])
			return (0);
		b++;
	}
	str[b] = '\0';
	return (create_int_val(str, isneg));
}
    
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		num;
	int		isneg;

	num = 0;
	i = 0;
	nptr = ft_ignoreprint(nptr);
	isneg = ft_isnegative(nptr);
	if (*nptr == '\0')
		return (0);
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(nptr[i]))
		i++;
	if (i > 10)
		return (0);
	if (i == 10)
		return (int_near_overflow((char * )nptr, isneg));
	i = 0;
	while (ft_isdigit(nptr[i]))
		num = (nptr[i++] - '0') + (num * 10);
	if (isneg)
		num = -num;
	return ((int)num);
}

/*
int	main(void)
{
	char num[] = "\212 139";
	printf("Return: %d\n", ft_atoi(num));
	printf("Return: %d\n", atoi(num));
}
*/
