/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:21:17 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:59 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char	*allocate_substring(size_t len)
{
	char	*substring;

	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	substring[len] = '\0';
	return (substring);
}

static void	copy_substring(char *substring, const char *s, unsigned int start,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_length;
	char	*substring;

	if (s == NULL)
		return (NULL);
	str_length = ft_strlen(s);
	if (start >= str_length)
	{
		substring = allocate_substring(0);
		return (substring);
	}
	if (len > str_length - start)
		len = str_length - start;
	substring = allocate_substring(len);
	if (substring == NULL)
		return (NULL);
	copy_substring(substring, s, start, len);
	return (substring);
}
