/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:01:23 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/10/20 18:02:45 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nbr)
{
	char	result[11];
	int		i;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 10;
	result[i] = '\0';
	while (nbr > 0)
	{
		result[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (write(1, &result[i], 11 - i - 1));
}
