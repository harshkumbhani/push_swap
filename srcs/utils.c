/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:46:27 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/22 09:05:14 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_freearr(char	**arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}

void	ft_freelist(t_cdlist **head)
{
	t_cdlist	*current;
	t_cdlist	*next;

	current = (*head);
	next = NULL;
	while (current->next != (*head))
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
	free(next);
	return ;
}