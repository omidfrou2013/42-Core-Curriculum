/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:41:58 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/12 22:23:49 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	buffer[10];
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	while (nb > 0 || i == 0)
	{
		buffer[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (neg)
		ft_putchar('-');
	while (--i >= 0)
		ft_putchar(buffer[i]);
}
