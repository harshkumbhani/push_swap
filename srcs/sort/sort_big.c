/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:49:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/01 14:02:10 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

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
	int			max;
	t_cdlist	*first;
	int			i;

	first = (*stack)->b;
	max = list_max(first);
	while (1)
	{
		i = 0;
		if (first->index == max)
			break;
		first = first->next;
		i++;
	}
	while (1)
	{
		if ((*stack)->b == first)
			break;
		if (i < (int)ft_list_len(&(*stack)->b) / 2)
			do_operation(stack, RB);
		else
			do_operation(stack, RRB);
	}
}

static int	pos_in_b(t_cdlist *b, int index)
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

int	case_rarb(t_stack **stack, int index)
{
	int	i;

	i = pos_in_b((*stack)->b, index);
	if (i < return_pos((*stack)->a, index))
		i = return_pos((*stack)->a, index);
	return (i);
}

int	case_rrarrb(t_stack **stack, int index)
{
	int	i;

	i = ft_list_len(&(*stack)->b) - pos_in_b((*stack)->b, index);
	if (i < ft_list_len(&(*stack)->a) - return_pos((*stack)->a, index))
		i = ft_list_len(&(*stack)->a) - return_pos((*stack)->a, index);
	return (i);
}

int	case_rarrb(t_stack **stack, int index)
{
	int	i;

	i = ft_list_len(&(*stack)->b) - pos_in_b((*stack)->b, index);
	i = return_pos((*stack)->a, index) + i;
	return (i);
}

int	case_rrarb(t_stack **stack, int index)
{
	int	i;

	i = pos_in_b((*stack)->b, index);
	i = ft_list_len(&(*stack)->a) - return_pos((*stack)->a, index) + i;
	return (i);
}

int	apply_rarb(t_stack **stack, int index)
{
	while ((*stack)->a->index != index && pos_in_b((*stack)->b, index) > 0 )
		do_operation(stack, RR);
	while ((*stack)->a->index != index)
		do_operation(stack, RA);
	while (pos_in_b((*stack)->b, index) > 0)
		do_operation(stack, RB);
	return (-1);
}

int	apply_rrarrb(t_stack **stack, int index)
{
	int	i;

	i = ft_list_len(&(*stack)->b);
	while ((*stack)->a->index != index && i - pos_in_b((*stack)->b, index) > 0 )
		do_operation(stack, RRR);
	while ((*stack)->a->index != index)
		do_operation(stack, RRA);
	while (ft_list_len(&(*stack)->b) - pos_in_b((*stack)->b, index) > 0)
	{
		do_operation(stack, RRB);
		if (pos_in_b((*stack)->b, index)  == 0)
			break ;
	}
	return (-1);
}

int	apply_rrarb(t_stack **stack, int index)
{
	while ((*stack)->a->index != index)
		do_operation(stack, RRA);
	while (pos_in_b((*stack)->b, index) > 0)
		do_operation(stack, RB);
	return (-1);
}

int	apply_rarrb(t_stack **stack, int index)
{
	int	i;

	i = ft_list_len(&(*stack)->b);
	while ((*stack)->a->index != index)
		do_operation(stack, RA);
	while ((&(*stack)->b) - pos_in_b((*stack)->b, index) > 0)
	{
		do_operation(stack, RRB);
		if (pos_in_b((*stack)->b, index)  == 0)
			break ;
	}	
	return (-1);
}

static int	moves_ab(t_stack	**stack)
{
	int			mov;
	t_cdlist	*stacka;

	stacka = (*stack)->a;
	mov = case_rarb(stack, stacka->index);
	while (1)
	{
		if (mov > case_rarb(stack, stacka->index))
			mov = case_rarb(stack, stacka->index);
		if (mov > case_rrarrb(stack, stacka->index))
			mov = case_rrarrb(stack, stacka->index);
		if (mov > case_rarrb(stack, stacka->index))
			mov = case_rarrb(stack, stacka->index);
		if (mov > case_rrarb(stack, stacka->index))
			mov = case_rrarb(stack, stacka->index);
		stacka = stacka->next;
		if (stacka == (*stack)->a)
			break ;
	}
	return (mov);
}

static void	move_atob(t_stack **stack)
{
	int			moves;
	t_cdlist	*tmpa;
	t_cdlist	*tmpb;

	tmpb = (*stack)->b;
	while (ft_list_len(&(*stack)->a) > 0)
	{
		tmpa = (*stack)->a;
		moves = moves_ab(stack);
		while (moves >= 0)
		{
			if (moves == case_rarb(stack, tmpa->index))
				moves = apply_rarb(stack, tmpa->index);
			else if (moves == case_rrarrb(stack, tmpa->index))
				moves = apply_rrarrb(stack, tmpa->index);
			else if (moves == case_rarrb(stack, tmpa->index))
				moves = apply_rarrb(stack, tmpa->index);
			else if (moves == case_rrarb(stack, tmpa->index))
				moves = apply_rrarb(stack, tmpa->index);
			else
				tmpa = tmpa->next;
		}
		do_operation(stack, PB);
	}
}

void	sort_big(t_stack **stack)
{
	if (is_sorted((*stack)->a))
		return ;
	if (is_sorted((*stack)->a) == FALSE)
		do_operation(stack, PB);
	if (is_sorted((*stack)->a) == FALSE)
		do_operation(stack, PB);
	if (ft_list_len(&(*stack)->a) > 0)
		move_atob(stack);
	stackb_max_to_top(stack);
	//ft_printf("\n\nStack b:\n");
	//ft_print_index(&(*stack)->b);
	while (ft_list_len(&(*stack)->b) > 0)
		do_operation(stack, PA);
}
