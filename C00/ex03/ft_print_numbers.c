/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:32:18 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/15 21:12:32 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_numbers(void)
{
    char    digits;

    digits = '0';
    while (digits <= '9') 
    {
        write(1, &digits, 1);
        digits++;
    }
}
int main (void)
{
    char dg;
    
    dg = '0';
    while (dg <= '9')
    {
        write(1, &dg, 1);
        dg++;
    }
    write(1, "\n", 1);
    return (0);
}