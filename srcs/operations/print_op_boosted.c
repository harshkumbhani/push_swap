/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_boosted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:41:09 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 14:07:58 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rarb(t_stack **stack, int index)
{
	while ((*stack)->a->index != index && pos_in_b((*stack)->b, index) > 0)
		do_operation(stack, RR, 0);
	while ((*stack)->a->index != index)
		do_operation(stack, RA, 0);
	while (pos_in_b((*stack)->b, index) > 0)
		do_operation(stack, RB, 0);
	return (-1);
}

int	do_rrarrb(t_stack **stack, int index)
{
	int	i;
	int	k;

	k = pos_in_b((*stack)->b, index);
	i = ft_list_len(&(*stack)->b);
	while (k != 0 && (*stack)->a->index != index
		&& i - pos_in_b((*stack)->b, index) > 0)
	{
		do_operation(stack, RRR, 0);
		k = pos_in_b((*stack)->b, index);
	}
	while ((*stack)->a->index != index)
		do_operation(stack, RRA, 0);
	while (i - pos_in_b((*stack)->b, index) > 0)
	{
		if (pos_in_b((*stack)->b, index) == 0)
			break ;
		do_operation(stack, RRB, 0);
	}
	return (-1);
}

int	do_rrarb(t_stack **stack, int index)
{
	while ((*stack)->a->index != index)
		do_operation(stack, RRA, 0);
	while (pos_in_b((*stack)->b, index) > 0)
		do_operation(stack, RB, 0);
	return (-1);
}

int	do_rarrb(t_stack **stack, int index)
{
	int	i;

	i = ft_list_len(&(*stack)->b);
	while ((*stack)->a->index != index)
		do_operation(stack, RA, 0);
	while (i - pos_in_b((*stack)->b, index) > 0)
	{
		if (pos_in_b((*stack)->b, index) == 0)
			break ;
		do_operation(stack, RRB, 0);
	}	
	return (-1);
}
