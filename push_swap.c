/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 15:34:40 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_printf(const char *format, ...);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argv;
	if (argc < 2)
		return (EXIT_FAILURE);
	parse();
	ft_printf("Invalid number of Arguments\n");
	return (0);
}
