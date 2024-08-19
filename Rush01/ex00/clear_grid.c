/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeigner <mdeigner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:00:47 by mdeigner          #+#    #+#             */
/*   Updated: 2024/08/11 16:42:05 by mdeigner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	clear_grid(int grid[4][4])
{
	int	xpos;
	int	ypos;

	ypos = 0;
	while (ypos < 4)
	{
		xpos = 0;
		while (xpos < 4)
		{
			grid[ypos][xpos] = 0;
			xpos++;
		}
		ypos++;
	}
}
