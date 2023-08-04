/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:49:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 11:06:20 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	find_cheapest_case(t_stack	**stack, int index)
{
	t_moves	moves;
	int		tmp_moves;

	moves.num_moves = case_rarb(stack, index);
	moves.case_id = RARB;
	tmp_moves = case_rrarrb(stack, index);
	if (tmp_moves < moves.num_moves)
	{
		moves.num_moves = case_rrarrb(stack, index);
		moves.case_id = RRARRB;
	}
	tmp_moves = case_rarrb(stack, index);
	if (tmp_moves < moves.num_moves)
	{
		moves.num_moves = case_rarrb(stack, index);
		moves.case_id = RARRB;
	}
	tmp_moves = case_rrarb(stack, index);
	if (tmp_moves < moves.num_moves)
	{
		moves.num_moves = case_rrarb(stack, index);
		moves.case_id = RRARB;
	}
	return (moves);
}

static int	num_moves(t_stack **stack)
{
	int			min_moves;
	int			min_index;
	t_cdlist	*stacka;
	t_moves		tmp;

	stacka = (*stack)->a;
	tmp = find_cheapest_case(stack, stacka->index);
	min_moves = tmp.num_moves;
	min_index = stacka->index;
	stacka = stacka->next;
	while(stacka != (*stack)->a)
	{
		tmp = find_cheapest_case(stack, stacka->index);
		if (tmp.num_moves < min_moves)
		{
			min_moves = tmp.num_moves;
			min_index = stacka->index;
		}
		stacka = stacka->next;
	}
	return (min_index);
}

static void	apply_cheapest_case(t_stack **stack, int index)
{
	t_moves moves;

	moves = find_cheapest_case(stack, index);
	if (moves.case_id == RARB)
		do_operation(stack, RARB, index);
	if (moves.case_id == RRARRB)
		do_operation(stack,RRARRB, index);
	if (moves.case_id == RARRB)
		do_operation(stack, RARRB, index);
	if (moves.case_id == RRARB)
		do_operation(stack, RRARB, index);
}

static void	move_atob(t_stack **stack)
{
	int	min_index;

	while (ft_list_len(&(*stack)->a) > 0)
	{
		min_index = num_moves(stack);
		apply_cheapest_case(stack, min_index);
		do_operation(stack, PB, 0);
	}
}

void	sort_big(t_stack **stack)
{
	if (is_sorted((*stack)->a))
		return ;
	if (is_sorted((*stack)->a) == FALSE)
		do_operation(stack, PB, 0);
	if (is_sorted((*stack)->a) == FALSE)
		do_operation(stack, PB, 0);
	if (ft_list_len(&(*stack)->a) > 0)
		move_atob(stack);
	stackb_max_to_top(stack);
	while (ft_list_len(&(*stack)->b) > 0)
		do_operation(stack, PA, 0);
}
