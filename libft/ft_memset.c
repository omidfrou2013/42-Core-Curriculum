/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:44 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:46 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int v, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)v;
		i++;
	}
	return (ptr);
}
