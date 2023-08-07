/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 13:59:03 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include "sort.h"

//void	check_leaks(void)
//{
//	system("leaks push_swap");
//}
//atexit(check_leaks);

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (EXIT_FAILURE);
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (EXIT_FAILURE);
	if (ft_parse(argc, argv, &stack) == EXIT_FAILURE)
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	sort(&stack);
	ft_free(NULL, &stack);
	return (EXIT_SUCCESS);
}
