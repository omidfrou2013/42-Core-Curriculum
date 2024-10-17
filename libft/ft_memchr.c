/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:16 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:42 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*p;

	p = (const unsigned char *)ptr;
	while (num > 0)
	{
		if (*p == (unsigned char)value)
		{
			return ((void *)p);
		}
		p++;
		num--;
	}
	return (NULL);
}
