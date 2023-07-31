/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:49:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/31 13:37:04 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"
#define CHUNK_COUNT	5

static int	return_pos(t_cdlist	*stack, int index)
{
	int			pos;
	t_cdlist	*tmp;

	pos = 0;
	tmp = stack;
	while (1)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
		if (tmp == stack)
			break ;
	}
	return (pos);
}

static void	stackb_max_to_top(t_stack **stack)
{
	int	max;
	int	stack_len;
	t_cdlist	*first;

	first = (*stack)->b;
	stack_len = ft_list_len(&first) / 2;
	max = list_max(first);
	while (1)
	{
		if ((*stack)->b->index == max)
			break ;
		if (return_pos(first, max) < stack_len)
			do_operation(stack, RB);
		else
			do_operation(stack, RRB);
	}
}

static	void	find_and_move(t_stack **stack)
{
	t_cdlist	*firsta;
	t_cdlist	*firstb;
	int			index;
	int			tmp;

	tmp = 0;
	firsta = (*stack)->a;
	firstb = (*stack)->b;
	if (firsta->index > list_max(firstb) || firsta->index < list_min(firstb))
	{
		stackb_max_to_top(stack);
		return ;
	}
	while (1)
	{
		
		break ;
	}
	return ;
}

void	sort_big(t_stack **stack)
{
	int	max;
	t_cdlist	*tmp;
	int	i;

	i = 0;
	max = 0;
	if (is_sorted((*stack)->a))
		return ;
	do_operation(stack, PB);
	do_operation(stack, PB);
	while (ft_list_len(&(*stack)->a) > 0)
	{
		// Find the cheapeast index to move to stack B from stack A
		// cheapest index
		find_and_move(stack);
		// Find the position in the for the current element in stack B
		// push to stack b
		do_operation(stack, PB);
	}
	while (ft_list_len(&(*stack)->b) > 0)
	{
		tmp = (*stack)->b;
		max = list_max((*stack)->b);
		while (1)
		{
			i = 0;
			if (tmp->index == max)
				break;
			tmp = tmp->next;
			i++;
		}
		while (1)
		{
			if ((*stack)->b == tmp)
				break;
			if (i < (int)ft_list_len(&(*stack)->b) / 2)
				do_operation(stack, RB);
			else
				do_operation(stack, RRB);
		}
		do_operation(stack, PA);
	}
}
