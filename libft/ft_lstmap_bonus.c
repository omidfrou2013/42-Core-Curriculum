/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:35:19 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:39 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	clear_list(t_list **list, void (*del)(void *))
{
	t_list	*node;

	while (*list)
	{
		node = *list;
		*list = (*list)->next;
		del(node->content);
		free(node);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last_node;
	t_list	*new_node;

	new_list = NULL;
	last_node = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			clear_list(&new_list, del);
			del(f(lst->content));
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = NULL;
		if (!new_list)
			new_list = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (new_list);
}
