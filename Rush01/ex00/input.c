/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeigner <mdeigner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:50:15 by mdeigner          #+#    #+#             */
/*   Updated: 2024/08/11 21:34:52 by mdeigner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

int	is_valid_char(char c)
{
	return ((c >= '0' && c <= '9') || c == ' ');
}

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

int	check_input(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!is_valid_input(av[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	*get_numbers(char *str)
{
	int	i;
	int	j;
	int	*grid;

	grid = malloc(sizeof(int) * 16);
	if (!grid)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			grid[j++] = ft_atoi(str + i);
		i++;
	}
	return (grid);
}
