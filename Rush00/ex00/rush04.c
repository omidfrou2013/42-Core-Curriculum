/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:45:56 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/08/04 08:47:08 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	r;
	int	col;

	r = 1;
	while (r <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((r == 1 & col == 1) || (r == y & col == x & y != 1 & x != 1))
				ft_putchar('A');
			if ((r == 1 & col == x & x != 1) || (r == y & col == 1 & y != 1))
				ft_putchar('C');
			if (col != 1 & col != x & (r == 1 || r == y))
				ft_putchar('B');
			if (r != 1 & r != y & (col == 1 || col == x))
				ft_putchar('B');
			if (r != 1 & r != y & col != 1 & col != x)
				ft_putchar(' ');
			col++;
		}
		r++;
		write(1, "\n", 1);
	}
}
