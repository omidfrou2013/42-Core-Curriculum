/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:09:19 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/16 11:34:53 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	k;

	k = 0;
	while (k < n && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		k++;
	}
	while (k < n)
	{
		*dest = '\0';
		dest++;
		k++;
	}
	return (dest - n);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		
	}
}