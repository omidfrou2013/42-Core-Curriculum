# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 01:36:18 by ofirouzb          #+#    #+#              #
#    Updated: 2025/01/14 16:19:48 by ofirouzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = pipex
CFLAGS      = -Wall -Wextra -Werror
SRCS        = pipex.c \
              ft_free_split.c ft_putendl_fd.c ft_split.c  \
              ft_strdup.c ft_strjoin.c ft_strlen.c  \
              ft_strncmp.c get_cmd_path.c \
              
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -fsanitize=address -g
debug: $(NAME)

.PHONY: all clean fclean re bonus debug
