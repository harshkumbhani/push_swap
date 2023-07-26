/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:23:40 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 11:31:19 by hkumbhan         ###   ########.fr       */
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

// FUNCTIONS DEFS FOR SWAPPING 

void	swap(t_cdlist **stack);
void	swap_both(t_stack **stack);

// FUNCTIONS DEFS FOR ROTATION

void	rot(t_cdlist **stack);
void	rot_both(t_stack **stack);
void	rev_rot(t_cdlist **stack);
void	rev_rot_both(t_stack **stack);

// Functions definitions for pushing

void	pa(t_stack **stack);
void	pb(t_stack **stack);

// Functions for prinitng the opearations

void	do_operations(t_stack **stack, int operation);

#endif