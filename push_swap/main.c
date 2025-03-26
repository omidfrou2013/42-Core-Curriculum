/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:18:15 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/03/05 19:39:28 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_push(char **argv)
{
	t_stack	s;
	int		j;
	int		length1;

	j= 0;
	length1 = ps_strlen(argv);
	s.a = malloc(length1 * sizeof(int));
	s.size_a = length1;
	s.b = malloc(length1 * sizeof(int));
	if (!s.b)
		free(s.a);
	s.size_b = 0;
	while (j < length1)
	{
		s.a[j] = atoi_error(argv[j], s.a);
		j++;
	}
		
	duplicate(s.a, length1);
	which_sort(&s, length1);
	// free_all(s.a,s.b)
	free(s.a);
	free(s.b);
}

int	main(int argc, char **argv)
{
	char	**splitav;
	int		i;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			splitav = ft_split(*argv);
			if (!splitav)
				return (0);
			argv = splitav;
		}
		run_push(argv);
		if (argc == 2)
		{
			i = 0;
			while (splitav[i])
				free(splitav[i++]);
			free(splitav);
		}
		return (0);
	}
	return (0);
}
