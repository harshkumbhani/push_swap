/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 07:46:10 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/27 10:44:16 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

static void	ft_rev_rot_ops(t_stack **stack, int operation)
{
	if (operation == RRA)
	{
		rev_rot(&((*stack)->a));
		ft_printf("rra\n");
	}
	else if (operation == RRB)
	{
		rev_rot(&(*stack)->b);
		ft_printf("rrb\n");
	}
	else if (operation == RRR)
	{
		rev_rot_both(stack);
		ft_printf("rrr\n");
	}
}

static void	ft_rot_ops(t_stack **stack, int operation)
{
	if (operation == RA)
	{
		rot(&((*stack)->a));
		ft_printf("ra\n");
	}
	else if (operation == RB)
	{
		rot(&(*stack)->b);
		ft_printf("rb\n");
	}
	else if (operation == RR)
	{
		rot_both(stack);
		ft_printf("rr\n");
	}
}

static void	ft_push_ops(t_stack **stack, int operation)
{
	if (operation == PA)
	{
		pa(stack);
		ft_printf("pa\n");
	}
	else if (operation == PB)
	{
		pb(stack);
		ft_printf("pb\n");
	}
}

static void	ft_swap_ops(t_stack **stack, int operation)
{
	if (operation == SA)
	{
		swap(&((*stack)->a));
		ft_printf("sa\n");
	}
	else if (operation == SB)
	{
		swap(&((*stack)->b));
		ft_printf("sb\n");
	}
	else if (operation == SS)
	{
		swap_both(stack);
		ft_printf("ss\n");
	}
}

void	do_operation(t_stack **stack, int operation)
{
	if (operation == SA || operation == SB || operation == SS)
		ft_swap_ops(stack, operation);
	else if (operation == PA || operation == PB)
		ft_push_ops(stack, operation);
	else if (operation == RA || operation == RB || operation == RR)
		ft_rot_ops(stack, operation);
	else if (operation == RRA || operation == RRB || operation == RRR)
		ft_rev_rot_ops(stack, operation);
}
