/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:32:18 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/15 21:19:46 by ofirouzb         ###   ########.fr       */
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
    int n;

    n = '0';
    if (n < 0)
    {
        write(1, "N", 1);
    }
    else
    {
        write(1, "P", 1)
    }
    return (0);
}