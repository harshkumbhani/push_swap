/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:49:44 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/31 09:46:32 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

void	sort_3(t_stack **stack)
{
	t_cdlist	*top;

	top = (*stack)->a;
	if (is_sorted((*stack)->a) == TRUE)
		return ;
	if (top->index > top->next->index
		&& top->index > top->next->next->index)
		do_operation(stack, RA);
	top = (*stack)->a;
	if (top->next->index > top->index
		&& top->next->index > top->next->next->index)
		do_operation(stack, RRA);
	top = (*stack)->a;
	if (top->index > top->next->index)
		do_operation(stack, SA);
}

static int	count_rotations(t_cdlist *stack, int index)
{
	t_cdlist	*tmp;
	int			count;

	count = 0;
	tmp = stack;
	while (1)
	{
		if (tmp->index == index)
			break;
		count++;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (count);
}

static void sort_5(t_stack **stack, int i)
{
	int	len;

	len = ft_list_len(&(*stack)->a) + 1;
	if (is_sorted((*stack)->a) == TRUE)
		return ;
	while (++i < --len)
	{
		while ((*stack)->a->index != i)
		{
			if (count_rotations((*stack)->a, i) <= len / 2)
				do_operation(stack, RA);
			else
				do_operation(stack, RRA);
		}
		if (is_sorted((*stack)->a) == TRUE)
			break ;
		do_operation(stack, PB);
		if (ft_list_len(&((*stack)->a)) == 3)
		{
			sort_3(stack);
			break ;
		}
	}
	while (ft_list_len(&((*stack)->b)) > 0)
		do_operation(stack, PA);
}

void	sort(t_stack **stack)
{
	size_t	len;
	int		i;

	i = -1;
	len = ft_list_len(&(*stack)->a);
	if (len == 1)
		return ;
	if (len == 2)
	{
		if (is_sorted((*stack)->a) == FALSE)
			do_operation(stack, SA);
	}
	if (len == 3)
		sort_3(stack);
	else if (len <= 5)
		sort_5(stack, i);
	else
		sort_big(stack);
	return ;
}
