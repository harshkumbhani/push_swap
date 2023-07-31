/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:10:24 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/31 09:23:06 by hkumbhan         ###   ########.fr       */
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
			break;
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
			break;
	}
	return (max_index);
}
