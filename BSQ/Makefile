# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakinen <amakinen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 10:25:38 by amakinen          #+#    #+#              #
#    Updated: 2024/01/31 17:33:34 by amakinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

# Add all .c files here
SRCS = \
	main.c \
	buffer.c \
	read_file.c \
	check_map.c \
	parse_map.c \
	solve.c \
	print_map.c \
	ft_isprint.c \
	ft_putchar.c \
	ft_putstr.c \

OBJS = $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -Werror $(CFLAGS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	cc $(CFLAGS) $^ -o $@

%.o : %.c
	cc $(CFLAGS) -c $< -o $@
