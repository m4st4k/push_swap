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
SRCS      = push_swap.c helperfunc/ft_get_next_token.c 
OBJS      = $(SRCS:.c=.o)

FTPRINTF       = ft_printf/libftprintf.a
FTPRINTF_DIR   = ft_printf
FTPRINTF_INC   = -I$(FTPRINTF_DIR)

all: $(NAME)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

$(NAME): $(FTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(FTPRINTF_INC) -c $< -o $@

clean:
	$(MAKE) -C $(FTPRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(FTPRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
