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
    s_paths = split_env_paths(env_paths);
    f_paths = find_full_path(s_paths, c_paths, path_index);
    ft_free_split(s_paths);
    return(f_paths);
}

char    *get_path_variable(char **envp)
{
    int env_index;

    env_index = -1;
    while (envp[++env_index])
    {
        if (ft_strncmp(envp[env_index], "PATH", 4) == 0)
            return (envp[env_index] + 5);
    }
    return (NULL);
}

void ft_run (char *cmd, char **envp)
{
    char *resolved_path;
    char *path_variable;
    char **command_arguments;

    command_arguments = ft_split(cmd, ' ');
    path_variable = get_path_variable(envp);
    reolved_path = construct_full_paths(path_variable, command_arguments);
    if (execve(resolved_path, command_arguments, envp) == -1)
    {
        ft_putstr_fd ("COMMAND NOT FOUND.");
        write(2, "\n", 1);
        f_free_split(command_arguments);
        exit(127);
    }
}
