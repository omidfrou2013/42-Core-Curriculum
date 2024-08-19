/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:32:18 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/15 21:09:18 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_print_reverse_alphabet(void) 
{
    char    letter;

    letter = 'z';
    while (letter >= 'a')
    {
        write(1, &letter, 1);
        letter--;
    }
}

int main (void)
{
    char    l;

    l = 'z';
    while (l >= 'a')
    {
        write(1, &l, 1);
        l--;
    }
    write(1, "\n", 1);
    return (0);
}