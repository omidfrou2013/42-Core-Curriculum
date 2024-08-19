/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_on_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeigner <mdeigner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:00:47 by mdeigner          #+#    #+#             */
/*   Updated: 2024/08/10 20:24:13 by mdeigner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output_on_grid(int grid[4][4])
{
	int	xpos;
	int	ypos;
	int	output;

	ypos = 0;
	while (ypos < 4)
	{
		xpos = 0;
		while (xpos < 4)
		{
			output = grid[ypos][xpos] + 48;
			write(1, &output, 1);
			write(1, " ", 1);
			xpos++;
		}
		write(1, "\n", 1);
		ypos++;
	}
}
