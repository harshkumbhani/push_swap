/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:39:49 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 13:51:02 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_check_and_execute_command(t_stack **stack, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap(&(*stack)->a);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		swap(&(*stack)->b);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stack);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		rot(&(*stack)->a);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		rot(&(*stack)->b);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		rev_rot(&(*stack)->a);;
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		rev_rot(&(*stack)->b);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack);
	else 
		write(2, "Error\n", 6);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	*command;
	int		read_size;
	char	op[5];
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
	while (1)
	{
		read_size = read(0, op, 3);
		if ( read_size == EOF)
			break ;
		command = get_next_line(0);
		printf("%s", command);
		_check_and_execute_command(&stack, command);
	}
	if (is_sorted_b(stack->a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	ft_free(NULL, &stack);
	return (EXIT_SUCCESS);
}
