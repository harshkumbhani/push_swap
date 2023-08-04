/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:37:42 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 13:49:46 by hkumbhan         ###   ########.fr       */
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

int	is_sorted_b(t_cdlist	*stack);

#endif