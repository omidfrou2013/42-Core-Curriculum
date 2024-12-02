/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:28 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:44 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (d == NULL && s == NULL)
		return (NULL);
	dest = (unsigned char *)d;
	src = (const unsigned char *)s;
	if (n == 0)
		return (d);
	while (n--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (d);
}
