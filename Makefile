# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 18:29:17 by ksellami          #+#    #+#              #
#    Updated: 2024/04/14 12:29:46 by ksellami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
HEADER = push_swap.h
FILES =  push_swap.c ft_split.c libft_utils2.c stack_utils.c small_sort.c opA.c opB.c  sort_algo.c pas_initialize.c libft_utils1.c
OBJS = ${FILES:%.c=%.o}
CC = cc 
CFLAGS=-Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJS} 
fclean: clean
	rm -f ${NAME}

re: fclean all
