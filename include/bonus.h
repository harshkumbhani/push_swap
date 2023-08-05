/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:37:42 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/05 08:26:56 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "push_swap.h"

void	_check_and_execute_command(t_stack **stack, char *str);

// Utils function definitions

void	ss(t_stack **stack);
void	rr(t_stack **stack);
void	rrr(t_stack **stack);

int		is_sorted_bonus(t_cdlist	*stack);

#endif