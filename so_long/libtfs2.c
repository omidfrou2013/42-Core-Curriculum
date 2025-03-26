/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtfs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:19 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/02/18 22:18:26 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
	{
		str[--len] = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (--len >= 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	**ft_split(char *str)
{
	int		i;
	int		i2;
	int		i3;
	char	**tab;

	i = 0;
	i2 = 0;
	if (!(tab = (char **)malloc(sizeof(**tab) * WD_NUM)))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			i3 = 0;
			if (!(tab[i2] = (char *)malloc(sizeof(char) * WD_LEN)))
				return (NULL);
			while (str[i] && str[i] > 32)
				tab[i2][i3++] = str[i++];
			tab[i2++][i3] = '\0';
		}
	}
	tab[i2] = NULL;
	return (tab);
}
