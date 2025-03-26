/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_validation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:58:17 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/02/25 22:51:54 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int *s)
{
	free(s);
	ft_putstr("Error\n");
	exit(1);
}

int	atoi_error(char *str, int *s)
{
	int				sign;
	unsigned int	i;
	unsigned long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(s);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > INT_MAX && sign == -1) || (num > INT_MAX && sign == 1))
		error(s);
	return (num * sign);
}

void	duplicate(int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (num[i] == num[j])
				error(num);
			j++;
		}
		i++;
		j = i + 1;
	}
}
