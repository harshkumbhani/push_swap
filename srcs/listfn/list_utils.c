/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:10:24 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 14:03:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	list_min(t_cdlist *stack)
{
	t_cdlist	*first;
	int			min_index;

	min_index = INT_MAX;
	first = (stack);
	while (1)
	{
		if (first->index < min_index)
			min_index = first->index;
		first = first->next;
		if (first == stack)
			break ;
	}
	return (min_index);
}

int	list_max(t_cdlist *stack)
{
	t_cdlist	*first;
	int			max_index;

	max_index = INT_MIN;
	first = (stack);
	while (1)
	{
		if (first->index > max_index)
			max_index = first->index;
		first = first->next;
		if (first == stack)
			break ;
	}
	return (max_index);
}

int	return_pos(t_cdlist	*stack, int index)
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

void	stackb_max_to_top(t_stack **stack)
{
	int			max;
	t_cdlist	*first;
	int			i;

	first = (*stack)->b;
	max = list_max(first);
	i = 0;
	while (1)
	{
		if (first->index == max)
			break ;
		first = first->next;
		i++;
	}
	while (1)
	{
		if ((*stack)->b == first)
			break ;
		if (i < (int)ft_list_len(&(*stack)->b) / 2)
			do_operation(stack, RB, 0);
		else
			do_operation(stack, RRB, 0);
	}
}

int	pos_in_b(t_cdlist *b, int index)
{
	int			pos;
	t_cdlist	*tmp;

	tmp = b;
	pos = 1;
	if (index > tmp->index && index < tmp->prev->index)
		pos = 0;
	else if (index > list_max(b) || index < list_min(b))
		pos = return_pos(b, list_max(b));
	else
	{
		tmp = b->next;
		while (1)
		{
			if (index < b->index && index > tmp->index)
				break ;
			pos++;
			b = b->next;
			tmp = tmp->next;
		}
	}
	return (pos);
}
