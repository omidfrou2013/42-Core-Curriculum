# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 19:41:44 by ofirouzb          #+#    #+#              #
#    Updated: 2025/02/18 22:23:45 by ofirouzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = Error_handling.c Flood_Fill.c Game_mechanics.c get_next_line.c \
		get_next_line_utils.c libft \
        load_images.c load_map.c movements.c parse_map.c render_map.c main.c \
        show_map_elements_error.c validate_map_elements.c ft_atoi.c ft_itoa.c ft_strnstr.c \
        ft_strncmp.c ft_strdup.c ft_split.c

CFLAGS = -Wall -Wextra -Werror
MLX = ./mlx/libmlx.a
OBJS = $(SRCS:.c=.o)
CC = cc

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	clear

$(MLX):
	cd ./mlx && make

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $^

clean:
	rm -f $(OBJS)
	cd ./mlx && make clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
