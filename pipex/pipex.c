/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:44:54 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/01/16 16:24:19 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **split_env_paths(char*env_paths)
{
    return(ft_split(env_paths, ':'));
}

char *find_full_path(char **s_paths, char **c_parts, int p_index)
{
    char *full_path;
    char *tmp;

    while (s_paths[p_index])
    {
        tmp = ft_strjoin(s_paths[p_index], "/");
        full_path = ft_strjoin(tmp, c_parts[0]);
        free(tmp);
        if (access(full_path, F_OK) == 0)
            return (full_path);
        free(full_path);
        p_index++;
    }
    return (c_parts[0]);
}

char *construct_full_path(char *env_paths, char **c_paths)
{
    char *s_paths;
    char *f_paths;
    int path_index;

    path_index = 0;
