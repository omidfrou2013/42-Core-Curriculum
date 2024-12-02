/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:57:09 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/20 19:00:09 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_negative(long *nbr, int *sign)
{
	if (*nbr < 0)
	{
		*sign = 1;
		*nbr = -(*nbr);
	}
}

int	ft_putnbr(int n, int fd)
{
	char	result[12];
	long	nbr;
	int		sign;
	int		i;

	nbr = n;
	if (nbr == 0)
		return (write(fd, "0", 1));
	sign = 0;
	ft_negative(&nbr, &sign);
	i = 11;
	result[i] = '\0';
	while (nbr > 0)
	{
		result[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign)
		result[--i] = '-';
	return (write(fd, &result[i], 12 - i - 1));
}
