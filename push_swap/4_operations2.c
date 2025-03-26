/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_operations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:09:29 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/02/25 22:27:06 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *s, int b)
{
	int	i;
	int	t;

	if (s->size_b == 0 || s->size_b == 1)
		return ;
	i = s->size_b - 1;
	t = s->b[i];
	while (i)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[i] = t;
	if (!b)
		ft_putstr("rrb\n");
}

void	rra(t_stack *s, int b)
{
	int	i;
	int	t;

	if (s->size_a == 0 || s->size_a == 1)
		return ;
	i = s->size_a - 1;
	t = s->a[i];
	while (i)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = t;
	if (!b)
		ft_putstr("rra\n");
}

void	rrr(t_stack *s, int b)
{
	int	i;
	int	t;

	if ((s->size_b == 0 || s->size_b == 1) || (s->size_a == 0
			|| s->size_a == 1))
		return ;
	i = s->size_a - 1;
	t = s->a[i];
	while (i)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = t;
	i = s->size_b - 1;
	t = s->b[i];
	while (i)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[i] = t;
	if (!b)
		ft_putstr("rrr\n");
}

void	sa(t_stack *s, int b)
{
	int	t;

	if (s->size_a == 0 || s->size_a == 1)
		return ;
	t = 0;
	t = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = t;
	if (!b)
		ft_putstr("sa\n");
}

void	sb(t_stack *s, int b)
{
	int	t;

	if (s->size_b == 0 || s->size_b == 1)
		return ;
	t = 0;
	t = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = t;
	if (!b)
		ft_putstr("sb\n");
}
