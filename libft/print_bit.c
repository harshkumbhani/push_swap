/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:50:26 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/19 07:58:23 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(int nb)
{
	int	i;
	int	res;
	
	res = 0;
	i = 7;
	while (i >= 0)
	{
		res = (nb >> i) & 1;
		res += '0';
		write(1, &res, 1);
		--i;	
	}
}

int main(void)
{
	int	nb;

	nb = 25;
	print_bits(nb);
	return (0);
}