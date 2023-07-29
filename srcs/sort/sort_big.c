/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:49:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/29 15:29:12 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"
#define CHUNK_COUNT	5

static int	has_elements_in_range(t_cdlist **a, int min, int max)
{
	t_cdlist	*tmp;

	tmp = (*a);
	while (1)
	{
		if ((*a)->index >= min && (*a)->index <= max)
			return (1);
		tmp = tmp->next;
		if (tmp == (*a))
			break;
	}
	return (0);
}

static void	move_to_top(t_stack **stack, int min, int max)
{
	int	len = ft_list_len(&(*stack)->a) / 2;
	t_cdlist	*first;
	int		i , j;
	t_cdlist	*second;

	i = 0;
	j = 0;
	first = (*stack)->a;
	second = (*stack)->a;
	while (1)
	{
		if (first->index >= min && first->index <= max)
			break ;
		i++;
		first = first->next;
		if (first == (*stack)->a)
			break;
	}
	//while (1)
	//{
	//	if (second->index >= min && second->index <= max)
	//		break ;
	//	j++;
	//	second = second->prev;
	//	if (second == (*stack)->a)
	//		break;
	//}
	if (i < len * 2 - i)
	{
		while ((*stack)->a != first)
			do_operation(stack, RA);
	}
	else
	{
		while ((*stack)->a != first)
			do_operation(stack, RRA);
	}
}

static void	move_to_top_b(t_stack **stack)
{
	t_cdlist	*firsta;
	t_cdlist	*firstb;
	t_cdlist	*tmp;
	int			tmp;
	int			listb_len;
	int			i;

	i = 0;
	listb_len = ft_list_len(&(*stack)->b);
	tmp = (*stack)->a->index + 1;
	firsta = (*stack)->a;
	firstb = (*stack)->b;
	tmp = (*stack)->b;
	while (1)
	{
		if (firstb->index == tmp)
			break;
		tmp++;
		firstb = firstb->next;
		if (firstb == (*stack)->b)
			break ;
	}
	while (1)
	{
		if (tmp == firstb || tmp == (*stack)->b)
			break ;
		i++;
		tmp = tmp->next;
	}
		if (i < len * 2 - i)
	{
	while ((*stack)->a->prev != firstb)
		do_operation(stack, RA);
	}
	else
	{
		while ((*stack)->a->prev != firstb)
			do_operation(stack, RRA);
	}
}

void	sort_big(t_stack **stack)
{
	int	list_len;
	int	chunk_size;
	int	remainder;
	int	lower_bound;
	int	upper_bound;
	int	i;
	int	index_to_move;

	list_len = ft_list_len(&(*stack)->a);
	chunk_size = list_len / CHUNK_COUNT;
	remainder = list_len % CHUNK_COUNT;
	i = 0;
	while (i < CHUNK_COUNT)
	{
		lower_bound = i * chunk_size;
		upper_bound = (i + 1) * chunk_size - 1;
		if (remainder > 0)
		{
			upper_bound++;
			remainder--;
		}
		while (has_elements_in_range((&(*stack)->a), lower_bound, upper_bound))
		{
			move_to_top(stack, lower_bound, upper_bound);
			//int correct_position_on_b = find_correct_position_on_b(stack, index_to_move);
			move_to_top_b(stack);
			do_operation(stack, PB);
		}
		i++;
	}
	while (ft_list_len(&(*stack)->b) > 0)
	{
		int	max_index = find_max_index(&(*stack)->b);
		move_to_top_b_stack(stack, max_index);
		do_operation(stack, PA);
	}
}
