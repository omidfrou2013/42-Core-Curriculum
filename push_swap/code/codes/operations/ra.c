/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:04:20 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/12/10 21:11:45 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	last = *a;
	while (last->next)
		last = last ->next;
	*a = temp->next;
	temp->next = NULL;
	last->next = temp;
}
