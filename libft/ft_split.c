/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:11:17 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/16 21:51:47 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	if (end <= start)
		return (NULL);
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **split, size_t i)
{
	while (i > 0)
	{
		free(split[--i]);
	}
	free(split);
}

static int	allocate_words(const char *s, char c, char **result,
		size_t word_count)
{
	size_t	i;
	size_t	word_index;
	size_t	start;
	size_t	end;

	i = 0;
	word_index = 0;
	while (s[i] && word_index < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		result[word_index] = copy_word(s, start, end);
		if (!result[word_index])
		{
			ft_free_split(result, word_index);
			return (0);
		}
		word_index++;
	}
	result[word_index] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!allocate_words(s, c, result, word_count))
	{
		ft_free_split(result, word_count);
		return (NULL);
	}
	return (result);
}
