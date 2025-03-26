/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:04:38 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/02/18 22:17:58 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_name(char *map_name)
{
	int cmp;
	size_t l;

	l = ft_strlen(map_name);
	cmp = ft_strncmp(map_name + l - 4, ".ber", 4);
	if (cmp)
		return (1);
	return (0);
}

int validate_args(int argc, char**argv)
{
	int fd;

	fd = open (argv[1], O_RDONLY);
	if (fd < 0 || argc != 2 || check_map_name(argv[1]) != 0)
	{
		error_message("Error\nInvalid Arguments or Files.");
		return (1);
	}
	close(fd);
	return (0);
}
void mlx_hooks(t_game g)
{
	mlx_hook(g.window, 3, 1L << 1, handle_move_funcion, &g);
	mlx_loop(g.mlx);
	mlx_hook(g.window, 17, 1L << 1, free_and_exit, &g);
}

int main(int argc, char **argv)
{
	t_game g;
	
	if (validate_args(argc, argv))
		return (1);
	if (read_file_map(&g, argv[1]) || map_validation_func(&g) || map_initialization(&g))
		return (free_all(&g, 1));
	mlx_hooks(g);
	return (free_all(&g, 0));
}
