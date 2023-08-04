/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:50:09 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 11:06:45 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "operations.h"

typedef struct s_moves
{
	int	num_moves;
	int	case_id;
}	t_moves;

// Function def to check if the list is sorted

int		is_sorted(t_cdlist	*stack);
void	sort_3(t_stack **stack);

// Function def to sort 3 numbers

void	sort(t_stack **stack);
void	sort_big(t_stack **stack);

// Utility function defs for sort

int		case_rarb(t_stack **stack, int index);
int		case_rrarrb(t_stack **stack, int index);
int		case_rrarb(t_stack **stack, int index);
int		case_rarrb(t_stack **stack, int index);

#endif
