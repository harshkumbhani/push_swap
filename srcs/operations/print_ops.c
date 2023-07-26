/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 07:46:10 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 11:31:06 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

static void	ft_rev_rot_ops(t_stack **stack, int operation)
{
	if (operation == RA)
	{
		rev_rot(&((*stack)->a));
		ft_printf("ra\n");
	}
	else if (operation == RB)
	{
		rev_rot(&(*stack)->b);
		ft_printf("rb\n");
	}
	else if (operation == RR)
	{
		rev_rot_both(stack);
		ft_printf("rr\n");
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

void	do_operations(t_stack **stack, int operation)
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
