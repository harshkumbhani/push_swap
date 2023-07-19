/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:19:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 15:51:26 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_number(av[i]))
			return ;
	}
}

size_t	ft_number(char	*av)
{
	int	i;

	i = 0;
	while ()
}