/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:53:34 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/02/18 21:59:26 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && *str - '0' > 7))
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*copy;
	size_t	i;

	length = ft_strlen(s);
	copy = malloc(length + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copy[i] = s[i];
		i++;
	}
	copy[length] = '\0';
	return (copy);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *substr, size_t length)
{
	size_t	i;
	size_t	j;

	if (*substr == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < length)
	{
		j = 0;
		while (substr[j] && str[i + j] == substr[j] && (i + j) < length)
			j++;
		if (substr[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
