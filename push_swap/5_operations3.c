/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_operations3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:10:43 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/02/25 22:27:21 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *s, int b)
{
	int	t;

	if (s->size_a == 0 || s->size_a == 1 || s->size_b == 0 || s->size_b == 1)
		return ;
	t = 0;
	t = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = t;
	t = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = t;
	if (!b)
		ft_putstr("ss\n");
}

int	push(t_stack *s, int len, int push)
{
	if (push == 0)
		pb(s, 0);
	else
		pa(s, 0);
	len--;
	return (len);
}
