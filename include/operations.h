/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:23:40 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 11:03:40 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

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
	RRR,
	RARB,
	RRARRB,
	RARRB,
	RRARB
} t_operations;

// FUNCTIONS DEFS FOR SWAPPING 

typedef struct s_cdlist t_cdlist;
typedef struct s_stack t_stack;

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

// Function definitions for multiple operations

int		do_rarb(t_stack **stack, int index);
int		do_rrarrb(t_stack **stack, int index);
int		do_rarrb(t_stack **stack, int index);
int		do_rrarb(t_stack **stack, int index);

// Functions for prinitng the opearations

void	do_operation(t_stack **stack, int operation, int index);

#endif