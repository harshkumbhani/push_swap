/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:49:44 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/27 17:04:21 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

static void	sort_3(t_stack **stack)
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

static void push_smallest_to_b(t_stack **stack, int len)
{
	t_cdlist	*tmp;
	int			i;
	int			j;

	j = -1;
	while (++j < 2)
	{
		tmp = (*stack)->a;
		i = 1;
		while (tmp->index != j)
		{
			tmp = tmp->next;
			i++;
		}
		while (i > 1 && (*stack)->a->index != j)
		{
			if (i > len / 2)
				do_operation(stack, RRA);
			else
				do_operation(stack, RA);
			i--;
		}
		do_operation(stack, PB);
	}
}

static void sort_5(t_stack **stack)
{
	int	len;
	
	len = ft_list_len(&(*stack)->a);
	push_smallest_to_b(stack, len);
	sort_3(stack);
	do_operation(stack, PA);
	do_operation(stack, PA);
}

void	sort(t_stack **stack)
{
	size_t	len;

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
	if (len == 5)
		sort_5(stack);
	return ;
}

//static void	sort_5(t_stack **stack)
//{
//	t_cdlist	*top_a;
//	t_cdlist	*top_b;
//	t_cdlist	*tmp;
//	size_t		i;

//	i = 1;
//	tmp = (*stack)->a;
//	//do_operation(stack, PB);
//	//do_operation(stack, PB);
//	//sort_3(stack);
//	top_a = (*stack)->a;
//	top_b = (*stack)->b;
//	while (tmp->index != 0)
//	{
//		tmp = tmp->next;
//		i++;
//	}
//	while (i > 1)
//	{
//		do_operation(stack, RA);
//		i--;
//	}
//	do_operation(stack, PB);
//	i = 1;
//	tmp = (*stack)->a;
//	while (tmp->index != 1)
//	{
//		tmp = tmp->next;
//		i++;
//	}
//	while (i > 1)
//	{
//		do_operation(stack, RA);
//		i--;
//	}
//	do_operation(stack, PB);
//	sort_3(stack);
//	do_operation(stack, PA);
//	do_operation(stack, PA);
//}