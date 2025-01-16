/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:44:42 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/01/13 14:50:36 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_free_split(char **vector);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*get_cmd_path(char *cmd);
void	free_split(char **split);
void	child_process(char **argv, int *pipe_fd, int infile);
void	parent_process(char **argv, int *pipe_fd, int outfile);

#endif
