/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:08:18 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/10 00:00:35 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest_end;

	dest_end = dest;
	while (*dest_end != '\0')
	{
		dest_end++;
	}
	while (nb > 0 && *src != '\0')
	{
		*dest_end = *src;
		dest_end++;
		src++;
		nb--;
	}
	*dest_end = '\0';
	return (dest);
}
