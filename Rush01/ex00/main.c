/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:56:20 by mdeigner          #+#    #+#             */
/*   Updated: 2024/08/12 22:18:15 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	clear_grid(int grid[4][4]);
int		check_case(int grid[4][4], int pos, int entry[16]);
int		check_number(int grid[4][4], int pos, int num);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		*get_numbers(char *str);
void	ft_putstr(char *str);
int		check_input(int ac, char **av);

int	solve(int grid[4][4], int entry[16], int pos)
{
	int	size;

	if (pos == 16)
		return (1);
	size = 0;
	while (size <= 4)
	{
		size++;
		if (check_number(grid, pos, size) == 0)
		{
			grid[pos / 4][pos % 4] = size;
			if (check_case(grid, pos, entry) == 0)
			{
				if (solve(grid, entry, pos + 1) == 1)
					return (1);
			}
			else
				grid[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

int	check(int grid[4][4])
{
	int	xpos;
	int	ypos;

	ypos = 0;
	while (ypos < 4)
	{
		xpos = 0;
		while (xpos < 4)
		{
			if (grid[ypos][xpos] > 4 || grid[ypos][xpos] < 1)
			{
				ft_putstr("Error\n");
				return (1);
			}
			xpos++;
		}
		ypos++;
	}
	return (0);
}

void	display_solution(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	if (check(grid) == 0)
	{
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				ft_putnbr(grid[i][j]);
				if (j < 3)
					ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int	grid[4][4];
	int	*entry;

	clear_grid(grid);
	if (check_input(ac, av) == 1)
		return (0);
	entry = get_numbers(av[1]);
	if (solve(grid, entry, 0) == 1)
		display_solution(grid);
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
