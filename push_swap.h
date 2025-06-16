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
# include <stdbool.h>
# include <limits.h>

char	*str_dup(const char *s);
char	*get_next_token(char *str);
bool	parse_integer(const char *nptr, int *array_a);
void	check_dup_in_arr(int *stack_a, size_t arrlen);
void	handle_error(void *str);

#endif
