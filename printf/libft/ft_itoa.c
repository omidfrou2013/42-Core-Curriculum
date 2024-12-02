/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:19 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:34 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	handle_negative(int *n, char *str, int *sign, int *len)
{
	if (*n < 0)
	{
		*sign = 1;
		str[0] = '-';
		if (*n == -2147483648)
		{
			str[--(*len)] = '8';
			*n /= 10;
		}
		*n = -*n;
	}
}

static void	fill_string(int n, char *str, int len, int sign)
{
	while (len-- > sign)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	len = count_digits(n);
	sign = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	handle_negative(&n, str, &sign, &len);
	fill_string(n, str, len, sign);
	return (str);
}
