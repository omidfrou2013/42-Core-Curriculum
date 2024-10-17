/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:30 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:51 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*copy;
	size_t	i;

	length = ft_strlen(s);
	copy = malloc(length + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copy[i] = s[i];
		i++;
	}
	copy[length] = '\0';
	return (copy);
}
