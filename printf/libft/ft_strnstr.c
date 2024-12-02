/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:21:40 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:56 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static const char	*search_substr(const char *s, const char *ss, size_t length)
{
	while (*ss != '\0' && *s == *ss && length > 0)
	{
		s++;
		ss++;
		length--;
	}
	if (*ss == '\0')
		return (s);
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *substr, size_t length)
{
	const char	*s;
	const char	*start;
	const char	*result;

	if (*substr == '\0')
		return ((char *)str);
	if (length == 0)
		return (NULL);
	s = str;
	while (*s != '\0' && length > 0)
	{
		start = s;
		result = search_substr(s, substr, length);
		if (result != NULL)
			return ((char *)start);
		s = start + 1;
		length--;
	}
	return (NULL);
}
