/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeigner <mdeigner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:25:26 by mdeigner          #+#    #+#             */
/*   Updated: 2024/08/11 20:10:33 by mdeigner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_number(int grid[4][4], int pos, int num)
{
	int	i;

	i = 0;
	while (i < pos / 4)
	{
		if (grid[i][pos % 4] == num)
			return (1);
		i++;
	}
	i = 0;
	while (i < pos % 4)
	{
		if (grid[pos / 4][i] == num)
			return (1);
		i++;
	}
	return (0);
}
