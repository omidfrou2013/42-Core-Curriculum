/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:21:34 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/17 14:56:44 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = str + ft_strlen(str);
	while (last >= str)
	{
		if (*last == (unsigned char)c)
			return ((char *)last);
		last--;
	}
	return (NULL);
}
