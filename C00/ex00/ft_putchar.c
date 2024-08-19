/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:18:14 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/15 20:55:43 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main()
{
    ft_putchar('g');
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        write(1, &argv[1], 1);
    }
    return (0);
}