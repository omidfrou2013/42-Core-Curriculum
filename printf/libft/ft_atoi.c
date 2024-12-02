/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:07:15 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:23 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static void	skip_whitespace(const char **str)
{
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
		sign = -1;
	if (**str == '+' || **str == '-')
		(*str)++;
	return (sign);
}

static int	check_overflow(int result, int sign, char c)
{
	if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && (c - '0') > 7))
	{
		if (sign == 1)
			return (INT_MAX);
		return (INT_MIN);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	skip_whitespace(&str);
	sign = get_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		if (check_overflow(result, sign, *str))
			return (check_overflow(result, sign, *str));
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
