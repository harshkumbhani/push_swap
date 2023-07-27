/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:11:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/27 10:45:02 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

int	is_sorted(t_cdlist	*stack)
{
	t_cdlist	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->index > tmp->next->index)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
