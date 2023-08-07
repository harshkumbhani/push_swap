/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:39:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 14:02:39 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_check_and_execute_command(t_stack **stack, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap(&(*stack)->a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap(&(*stack)->b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stack);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rot(&(*stack)->a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rot(&(*stack)->b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rev_rot(&(*stack)->a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rev_rot(&(*stack)->b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack);
	else
		write(2, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	*command;

	if (argc < 2)
		return (EXIT_FAILURE);
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (EXIT_FAILURE);
	if (ft_parse(argc, argv, &stack) == EXIT_FAILURE)
		return (write(2, "Error\n", 6) * 0 + EXIT_FAILURE);
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		_check_and_execute_command(&stack, command);
	}
	if (is_sorted_bonus(stack->a) && stack->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free(NULL, &stack);
	return (EXIT_SUCCESS);
}

//void	check_leaks(void)
//{
//	system("leaks push_swap");
//}
//atexit(check_leaks);