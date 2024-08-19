/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:59:54 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/14 11:57:25 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_length(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert_and_print(int nbr, char *base, int base_len)
{
	if (nbr >= base_len)
		convert_and_print(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!is_valid_base(base))
		return ;
	base_len = base_length(base);
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		convert_and_print((unsigned int)2147483648U / base_len, base, base_len);
		ft_putchar(base[(2147483648U % base_len)]);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		convert_and_print((unsigned int)(-nbr), base, base_len);
	}
	else
	{
		convert_and_print((unsigned int)nbr, base, base_len);
	}
}
