CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror
NAME    =   libftprintf.a

SRC_DIR =   source
INC_DIR =   library
LIBFT_DIR =   libft

TARGET = main

MY_SOURCES	=	ft_printf.c 	\
				ft_print_p.c	\
				ft_print_u.c	\
				ft_print_x.c	\
				ft_print_s.c    \
				ft_putchar.c    \
				ft_putnbr.c

MY_OBJECTS =   $(MY_SOURCES:%.c=$(SRC_DIR)/%.o)

INCLUDES =   -I$(INC_DIR) -I$(LIBFT_DIR)
MY_HEADERS =   ft_printf.h

LIBFT   =   $(LIBFT_DIR)/libft.a

vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

all: $(TARGET)

$(SRC_DIR)/%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(MY_OBJECTS) $(LIBFT)
	cp $(LIBFT) .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(MY_OBJECTS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(TARGET)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(TARGET)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
