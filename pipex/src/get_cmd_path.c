/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:39:27 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/01/13 14:56:00 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *cmd)
{
	char	**paths;
	char	*path_var;
	char	*full_path;
	int		i;

	i = 0;
	path_var = getenv("PATH");
	paths = ft_split(path_var, ':');
	if (!path_var || !paths)
		return (NULL);
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, F_OK) == 0)
			return (ft_free_split(paths), full_path);
		free(full_path);
		i++;
	}
	return (ft_free_split(paths), NULL);
}
