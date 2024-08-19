/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofirouzb <ofirouzb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:39:32 by ofirouzb          #+#    #+#             */
/*   Updated: 2024/08/15 23:34:44 by ofirouzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
int main(void)
{
	int a = 5;
	int b = 3;
	int div, mod;
	
	ft_div_mod(&a, &b, &div, &mod);
	
	printf("%d\n", div);
	printf("%d\n", mod);
	
	retuen (0);
}