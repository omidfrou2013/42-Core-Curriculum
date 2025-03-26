/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_moresort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:58:00 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/03/03 22:17:39 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	more_case_a(t_stack *s, int len, int c)
{
	int	num;
	int	i;

	if (sorted(s->a, len, 0) == 1)
		return (1);
	num = len;
	if (len <= 3)
	{
		more_case_a_b(s, len);
		return (1);
	}
	if (!med(&i, s->a, len))
		return (0);
	while (len != num / 2 + num % 2)
	{
		if (s->a[0] < i && (len--))
			pb(s, 0);
		else if (++c)
			ra(s, 0);
	}
	while (num / 2 + num % 2 != s->size_a && c)
		rra(s, 0);
	return (more_case_a(s, num / 2 + num % 2, 0) && more_case_b(s, num / 2, 0));
}

int	more_case_b(t_stack *s, int len, int c)
{
	int	num;
	int	i;

	if (sorted(s->a, len, 0) == 1)
		while (len--)
			pa(s, 0);
	if (len <= 3)
	{
		more_case_a_b(s, len);
		return (1);
	}
	num = len;
	if (!med(&i, s->b, len))
		return (0);
	while (len != num / 2)
	{
		if (s->b[0] >= i && (len--))
			pa(s, 0);
		else if (++c)
			rb(s, 0);
	}
	while (num / 2 != s->size_b && c)
		rrb(s, 0);
	return (more_case_a(s, num / 2 + num % 2, 0) && more_case_b(s, num / 2, 0));
}

void	more_case_a_b(t_stack *s, int len)
{
	if (len == 3 && s->size_a == 3)
		three_case_a(s);
	else if (len == 2)
	{
		if (s->a[0] > s->a[1])
			sa(s, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 3 && s->a[0] > s->a[1] && s->a[2])
				sa(s, 0);
			else if (len == 3 && !(s->a[2] > s->a[0] && s->a[2] > s->a[1]))
				len = push(s, len, 0);
			else if (s->a[0] > s->a[1])
				sa(s, 0);
			else if (len++)
				pa(s, 0);
		}
	}
}

int	skip_whitespace(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	return (i);
}

size_t	ft_strlen(char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}
