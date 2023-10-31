/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:42:54 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/31 13:34:13 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int	stack_swap(t_stack *stack);
int	stack_transfer_top(t_stack *src, t_stack *dst);
int	stack_rotate_up(t_stack *stack);
int	stack_rotate_down(t_stack *stack);

int	stack_execute_command(char *command, int *op_count,
		t_stack *stack_a, t_stack *stack_b);

int	stack_read(int ac, char **av, t_stack *stack);
int	stack_find_val(t_stack stack, int new_val);
int	throw_error_push_swap(int error_nr);

#endif
