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

void    error_exit(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

void    child_process(char **argv, int *pipe_fd, int infile, char **envp)
{
    dup2(infile, STDIN_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(infile);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    ft_run(argv[2], envp);
}
void    parent_process(char **argv, int *pipe_fd, int outfile, char **envp)
{
    pid_t   pid2;
    int     sta1;

    pid2 = fork();
    if (pid2 == -1)
        error_exit("Fork error");
    if (pid2 == 0)
    {
        dup2(pipe_fd[0], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(pipe_fd[1]);
        ft_run(argv[3], envp);
    }
    close(pipe_fd[1]);
    close(outfile);
    waitpid(pid2, &sta1, 0);
    if (WIFEXITED(sta1))
        exit(WEXITSTATUS(sta1));
    else
        exit(1);
}

int main(int argc, char **argv, char **envp)
{
    int     pipe_fd[2];
    int     infile;
    int     outfile;
    pid_t   pid1;

    if (argc != 5)
        return (ft_putendl_fd("Usage: ./pipex infile cmd1 cmd2 outfile", 2), 1);
    if (pipe(pipe_fd) == -1)
        error_exit("File/pipe error");
    pid1 = fork();
    infile = open(argv[1], O_RDONLY);
    outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (infile < 0 || outfile < 0 || pid1 == -1)
        error_exit("file not created");
    if ((pid1) == 0)
        child_process(argv, pipe_fd, infile, envp);
   else
    {
        parent_process(argv, pipe_fd, outfile, envp);
        waitpid(pid1, NULL, 0);
    }
    return (0);
}
