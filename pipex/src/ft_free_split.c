/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:41:30 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/01/13 14:50:28 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **vector)
{
	int	i;

	i = 0;
	if (!vector)
		return ;
	while (vector[i])
		free(vector[i++]);
	free(vector);
}
