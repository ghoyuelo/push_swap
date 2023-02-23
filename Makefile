# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 17:04:45 by ghoyuelo          #+#    #+#              #
#    Updated: 2022/12/14 22:15:59 by ghoyuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCS = push_swap.h

SRC = push_swap.c\
	  controller.c\
	  controller2.c\
	  control_utils.c\
	  list_funtions.c\
	  element_funtions.c\
	  element_funtions2.c\
	  element_move.c\
	  movements.c\
	  resolve_utils.c\
	  stack_funtions.c\
	  bit_funtions.c

LIBFT = libft

OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror#-g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBFT)/libft.a
	@echo "\033[4;32mPush_swap is ready\033[0m"

clean:
	${MAKE} -C $(LIBFT) clean
	$(RM) $(OBJS) $(LIBFT)*.o

fclean: clean
	${MAKE} -C $(LIBFT) fclean
	$(RM) $(NAME) $(LIBFT)./libft/libft.a 

re: fclean all

.PHONY: all bonus clean fclean re