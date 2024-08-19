/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeigner <mdeigner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:47:41 by mdeigner          #+#    #+#             */
/*   Updated: 2024/08/11 20:10:47 by mdeigner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	highest;
	int	visible_towers;

	i = 0;
	highest = 0;
	visible_towers = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (grid[i][pos % 4] > highest)
			{
				highest = grid[i][pos % 4];
				visible_towers++;
			}
			i++;
		}
		if (entry[pos % 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_row_right(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	highest;
	int	visible_towers;

	i = 4;
	highest = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (--i >= 0)
		{
			if (grid[pos / 4][i] > highest)
			{
				highest = grid[pos / 4][i];
				visible_towers++;
			}
		}
		if (entry[12 + pos / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_col_down(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	highest;
	int	visible_towers;

	i = 3;
	highest = 0;
	visible_towers = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (grid[i][pos % 4] > highest)
			{
				highest = grid[i][pos % 4];
				visible_towers++;
			}
			i--;
		}
		if (entry[4 + pos % 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_row_left(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	highest;
	int	visible_towers;

	i = 0;
	highest = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (grid[pos / 4][i] > highest)
			{
				highest = grid[pos / 4][i];
				visible_towers++;
			}
			i++;
		}
		if (entry[8 + pos / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_case(int grid[4][4], int pos, int entry[16])
{
	if (check_row_left(grid, pos, entry) == 1)
		return (1);
	if (check_row_right(grid, pos, entry) == 1)
		return (1);
	if (check_col_down(grid, pos, entry) == 1)
		return (1);
	if (check_col_up(grid, pos, entry) == 1)
		return (1);
	return (0);
}
