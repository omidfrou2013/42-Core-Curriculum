/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_operations1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:57:57 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/03/05 19:45:03 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *s, int b)
{
	int	i;

	if (s->size_b == 0)
		return ;
	s->size_a++;
	i = s->size_a - 1;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = s->b[0];
	s->size_b--;
	i = 0;
	while (i < s->size_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	if (b == 0)
		ft_putstr("pa\n");//ft_showresult(1);
}

int ft_showresult(int i3)
{
	if (i3=1)
		ft_putstr("pa\n");
	if (i3=2)
		ft_putstr("pb\n");
}

void	pb(t_stack *s, int b)
{
	int	i;

	if (s->size_a == 0)
		return ;
	s->size_b++;
	i = s->size_b - 1;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = s->a[0];
	s->size_a--;
	i = 0;
	while (i < s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	if (b == 0)
		ft_putstr("pb\n");
}

void	ra(t_stack *s, int b)
{
	int	i;
	int	temp;

	if (s->size_a > 1)
	{
		temp = s->a[0];
		i = 0;
		while (i < s->size_a - 1)
		{
			s->a[i] = s->a[i + 1];
			i++;
		}
		s->a[s->size_a - 1] = temp;
		if (!b)
			ft_putstr("ra\n");
	}
}

void	rb(t_stack *s, int b)
{
	int	i;
	int	t;

	if (s->size_b == 0 || s->size_b == 1)
		return ;
	i = 0;
	t = s->b[i];
	while (++i < s->size_b)
		s->b[i - 1] = s->b[i];
	i = 0;
	s->b[i - 1] = t;
	if (!b)
		ft_putstr("rb\n");
}

void	rr(t_stack *s, int b)
{
	int	i;
	int	t;

	if ((s->size_b == 0 || s->size_b == 1) || (s->size_a == 0
			|| s->size_a == 1))
		return ;
	i = 0;
	t = s->a[i];
	while (++i < s->size_a)
		s->a[i - 1] = s->a[i];
	i = 0;
	t = s->b[i];
	while (++i < s->size_b)
		s->b[i - 1] = s->b[i];
	s->b[i - 1] = t;
	if (!b)
		ft_putstr("rb\n");
}
