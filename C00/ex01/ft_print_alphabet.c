/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:32:18 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/15 21:05:07 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_alphabet(void)
{
    char    letter;

    letter = 'a';
    while (letter <= 'z')
    {
        write(1, &letter, 1);
        letter++;
    }
}

int main (void)
{
    char l;

    l = 'a';
    while (l <= z)
    {
        write(1, &l, 1);
        l++;
    }
    write(1, "\n", 1);
    return (0);
}