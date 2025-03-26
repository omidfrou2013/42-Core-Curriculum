# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 19:37:32 by ofirouzb          #+#    #+#              #
#    Updated: 2025/03/03 21:21:34 by ofirouzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRCS	=	main.c libfts.c 1_validation.c 2_sort.c 3_operations1.c \
			4_operations2.c 5_operations3.c 6_moresort.c 

OBJS	=	$(SRCS:.c=.o)
CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re