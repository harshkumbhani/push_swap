/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/20 10:00:13 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print(int ac, char **av)
{
	char	**tmp;
	int		i;

	i = 0;
	while (++i < ac)
	{
		tmp = ft_split(av[i], ' ');
	}
	ft_freearr(tmp);
}

int	main(int argc, char **argv)
{
	//int	i;

	//i = 0;
	(void)argv;
	if (argc < 2)
		return (EXIT_FAILURE);
	ft_print(argc, argv);
	return (0);
}
