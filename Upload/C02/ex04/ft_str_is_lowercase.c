/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:24:15 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/08 11:05:32 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 'z' || str[i] < 'a')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int main()
{
	char	x[] = "a67ajksfhjl";

	printf("%d", ft_str_is_lowercase(x));
	return (0);
}
*/