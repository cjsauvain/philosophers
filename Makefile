# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 09:09:18 by jsauvain          #+#    #+#              #
#    Updated: 2022/09/26 11:33:03 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c check_errors.c 1_utils.c 2_utils.c init_utils.c life_utils.c \
		mutex_utils.c threads_utils.c get_status.c die.c free.c

OBJS = $(SRCS:.c=.o)

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread -g

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
