/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:21:22 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:58 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && is_in_set(s1[end - 1], set))
		end--;
	return (end);
}

static char	*create_trimmed_str(char const *s1, size_t start, size_t end)
{
	size_t	trimmed_len;
	char	*trimmed_str;
	size_t	i;

	trimmed_len = end - start;
	trimmed_str = malloc(trimmed_len + 1);
	if (trimmed_str == NULL)
		return (NULL);
	i = 0;
	while (i < trimmed_len)
	{
		trimmed_str[i] = s1[start + i];
		i++;
	}
	trimmed_str[trimmed_len] = '\0';
	return (trimmed_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start >= end)
	{
		trimmed_str = malloc(1);
		if (trimmed_str != NULL)
			trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	trimmed_str = create_trimmed_str(s1, start, end);
	return (trimmed_str);
}
