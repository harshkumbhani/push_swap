/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:50:09 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/27 10:58:44 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

#include "push_swap.h"
#include "operations.h"

// Function def to check if the list is sorted

int		is_sorted(t_cdlist	*stack);

// Function def to sort 3 numbers

void	sort(t_stack **stack);
#endif
