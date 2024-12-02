/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:35:45 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/11/04 14:42:10 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_s(char *str);
int	ft_print_p(size_t ptr);
int	ft_print_u(unsigned int nbr);
int	ft_print_x(unsigned int nbr, int isX);
int	ft_putchar(char c, int fd);
int	ft_putnbr(int n, int fd);
int	main();

#endif
