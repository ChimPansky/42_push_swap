/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:42:54 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/06 13:24:29 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# ifndef OPERATIONS_FD
#  define OPERATIONS_FD 1
# endif

typedef struct s_stack_node
{
	int					val;
	int					index;
	struct s_stack_node	*next;

}			t_snode;

typedef struct s_stack
{
	t_snode		*top;
	int			minind;
	int			maxind;
	size_t		size;
}			t_stack;

// Standard Stack Functions
size_t	stack_size(t_stack stack);
int		stack_find_val(t_stack stack, int new_val);
void	stack_reset(t_stack *stack);
void	snode_reset(t_snode *snode);
void	stack_update(t_stack *stack);
t_snode	*stack_pop(t_stack *stack);
int		stack_push_top_node(t_stack *stack, t_snode *snode);
int		stack_push_top_val(t_stack *stack, int val);
int		stack_push_bot_node(t_stack *stack, t_snode *snode);
int		stack_push_bot_val(t_stack *stack, int val);
t_snode	*stack_bottom(t_stack *stack);
void	stack_snode_del(t_snode *snode);
void	stack_clear(t_stack *stack);
//void	stack_print(t_stack stack);
//void	stacks_print(t_stack stack_a, t_stack stack_b);

// Stack Operations (swap, push, rotate, rrotate):
int		stack_swap(t_stack *stack);
int		stack_transfer_top(t_stack *src, t_stack *dst);
int		stack_rotate_up(t_stack *stack);
int		stack_rotate_down(t_stack *stack);
int		stack_execute_op(
			char *op, t_stack *stack_a, t_stack *stack_b, int print);

// Functions for calculating optimal operations for sorting:
int		get_top_distance(size_t stack_size, int index);
void	calc_rotation_cost(
			t_stack *stack_a, t_stack *stack_b, t_snode *cur_a, int *rot_cost);
int		find_target_b(t_stack *stack_b, int val_a);
int		find_target_a(t_stack *stack_b, int val_a);

// Functions for sorting:
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_three_stack(t_stack *stack);
void	push_a_to_b(t_stack *stack_a, t_stack *stack_b);
void	push_b_to_a(t_stack *stack_a, t_stack *stack_b);
void	rotate_elements_top(t_stack *stack_a, t_stack *stack_b,
			int index_a, int index_b);

// Stack reading and validating:
int		stack_read(int ac, char **av, t_stack *stack);
int		stack_check_sorted(t_stack stack_a);
int		ps_throw_error(int error_nr);

#endif
