# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbriant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 15:29:14 by dbriant           #+#    #+#              #
#    Updated: 2025/05/20 15:46:52 by dbriant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC        = cc
CFLAGS    = -Wall -Wextra -Werror
DELALL    = *.a *.o

NAME      = push_swap
SRCS      = push_swap.c helperfunc/get_next_token.c helperfunc/check_dup_in_arr.c helperfunc/parse_integer.c helperfunc/print_error.c \
			helperfunc/str_dup.c
OBJS      = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
