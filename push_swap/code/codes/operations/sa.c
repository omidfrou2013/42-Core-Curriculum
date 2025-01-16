/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:22:11 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/12/10 22:30:03 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}
