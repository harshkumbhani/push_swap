/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/28 14:20:29 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/operations.h"
#include "../include/sort.h"

void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	//atexit(check_leaks);
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
	//ft_print_index(&(stack->a));
	ft_free(NULL, &stack);
	return (EXIT_SUCCESS);
}
