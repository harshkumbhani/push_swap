/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:46:27 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/23 13:15:40 by hkumbhan         ###   ########.fr       */
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

void	ft_printf_list(t_cdlist **head)
{
	t_cdlist	*tmp;
	int			i;

	i = 1;
	tmp = (*head);
	while (tmp->next != (*head))
	{
		ft_printf("Node %d: %d\n", i++ , tmp->data);
		tmp = tmp->next;
	}
	ft_printf("Node %d: %d\n", i++ , tmp->data);
}
