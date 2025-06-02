/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:15:55 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/20 15:23:31 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_printf/ft_printf.h"

char	*get_next_token(char *str, int *arrlen);
int		int_overflow(char *str, size_t isneg);

#endif
