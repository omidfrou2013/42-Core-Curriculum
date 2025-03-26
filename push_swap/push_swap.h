/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:55:37 by ofirouzb          #+#    #+#             */
/*   Updated: 2025/03/03 22:17:32 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stack;

void	error(int *s);
int		atoi_error(char *str, int *s);
void	duplicate(int *num, int size);

void	three_case_a(t_stack *s);
int		sorted(int *s, int size, int n);
void	which_sort(t_stack *s, int size);
void	temp_sort(int *size_t, int size);
int		med(int *p, int *size_t, int size);

void	pa(t_stack *s, int b);
void	pb(t_stack *s, int b);
void	ra(t_stack *s, int b);
void	rb(t_stack *s, int b);
void	rr(t_stack *s, int b);

void	rrb(t_stack *s, int b);
void	rra(t_stack *s, int b);
void	rrr(t_stack *s, int b);
void	sa(t_stack *s, int b);
void	sb(t_stack *s, int b);

void	ss(t_stack *s, int b);
int		push(t_stack *s, int len, int push);

int		more_case_a(t_stack *s, int len, int c);
int		more_case_b(t_stack *s, int len, int c);
void	more_case_a_b(t_stack *s, int len);
int		skip_whitespace(char *str, int i);
size_t	ft_strlen(char *str);

void	ft_putstr(char *str);
int		ps_strlen(char **argv);
int		count_word(char *str);
char	*allocate_word(char *str);
char	**ft_split(char *str);

#endif
