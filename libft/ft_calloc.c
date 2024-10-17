/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:37:29 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:27 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t num_elem, size_t size_p_e)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*bptr;
	size_t			i;

	total_size = num_elem * size_p_e;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	bptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		bptr[i] = 0;
		i++;
	}
	return (ptr);
}
