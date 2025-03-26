/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:58:13 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/03/03 22:17:34 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_case_a(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s, 0);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		rra(s, 0);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s, 0);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 0);
		rra(s, 0);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s, 0);
}

int	sorted(int *s, int size, int n)
{
	int	i;

	if (n == 0)
	{
		i = 1;
		while (i < size)
		{
			if (s[i - 1] > s[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (s[i - 1] < s[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	which_sort(t_stack *s, int size)
{
	if (sorted(s->a, s->size_a, 0) == 0)
	{
		if (size == 2)
			sa(s, 0);
		else if (size == 3)
			three_case_a(s);
		else
			more_case_a(s, size, 0);
	}
}

void	temp_sort(int *size_t, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (size_t[i] > size_t[j])
			{
				temp = size_t[i];
				size_t[i] = size_t[j];
				size_t[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	med(int *p, int *size_t, int size)
{
	int	*temp;
	int	i;

	temp = (int *)malloc(size * sizeof(int));
	if (!temp)
		return (0);
	i = 0;
	while (i < size)
	{
		temp[i] = size_t[i];
		i++;
	}
	temp_sort(temp, size);
	*p = temp[size / 2];
	free(temp);
	return (1);
}
