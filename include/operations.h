/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:23:40 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 07:52:03 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "push_swap.h"

typedef enum	e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
} t_operations;

// FUNCTIONS FOR SWAPPING 

void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack);

// FUNCTIONS FOR ROTATION

void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack);

// Functions for prinitng the opearations

void	print_operations(t_operations operations);

#endif