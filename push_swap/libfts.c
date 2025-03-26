/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:01:26 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/03/03 22:18:13 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ps_strlen(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}

int	count_word(char *str)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str[i])
	{
		i = skip_whitespace(str, i);
		if (str[i])
		{
			c++;
			while (str[i] && str[i] > 32)
				i++;
		}
	}
	return (c);
}

char	*allocate_word(char *str)
{
	int		len;
	int		i;
	char	*word;

	len = ft_strlen(str);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		i = skip_whitespace(str, i);
		if (str[i])
		{
			tab[j] = allocate_word(&str[i]);
			if (!tab[j])
				return (NULL);
			j++;
			while (str[i] && str[i] > 32)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
