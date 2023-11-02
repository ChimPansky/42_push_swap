/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:42:54 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/02 15:47:57 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# ifndef OUTPUT_FD
#  define OUTPUT_FD 1
# endif

typedef struct s_stack_node
{
	int					val;
	size_t				index;
	struct s_stack_node *target;
	struct s_stack_node *next;

}			t_snode;

typedef struct s_stack
{
	t_snode	*top;
	int		minval;
	size_t	minind;
	int		maxval;
	size_t	maxind;
	size_t	size;
}			t_stack;

// Standard Stack Functions
void	stack_reset(t_stack *stack);
void	snode_reset(t_snode *snode);
void	stack_update(t_stack *stack);
int		stack_push_top_val(t_stack *stack, int val);
int		stack_push_bot_val(t_stack *stack, int val);
int		stack_push_top_node(t_stack *stack, t_snode *snode);
int		stack_push_bot_node(t_stack *stack, t_snode *snode);
t_snode	*stack_pop(t_stack *stack);
t_snode	*stack_bottom(t_stack *stack);
void	stack_snode_del(t_snode *snode);
void	stack_clear(t_stack *stack);

size_t	stack_size(t_stack stack);
int		stack_peek(t_snode snode);
int		stack_find_val(t_stack stack, int new_val);

void	stack_print(t_stack stack);
void	stacks_print(t_stack stack_a, t_stack stack_b);

// Stack Operations (swap, push, rotate, rrotate):
int	stack_swap(t_stack *stack);
int	stack_transfer_top(t_stack *src, t_stack *dst);
int	stack_rotate_up(t_stack *stack);
int	stack_rotate_down(t_stack *stack);

int	stack_execute_op(char *command, int *op_count,
		t_stack *stack_a, t_stack *stack_b, int replace_nl);

// Functions for calculating optimal operations:
int		get_move_top_cost(t_stack stack, size_t index);	//todo
t_snode	*get_target_snode(t_stack stack, t_snode snode);	//todo

// Functions for printing out sort-operations to File Descriptor fd:
void	print_and_execute(int fd, char *op, t_stack *stack_a,
	t_stack *stack_b, int *op_count);
void	snode_move_top(int fd, t_stack *stack, t_snode *snode); //todo
void	stack_three_sort(int fd, t_stack *stack, int *op_count);
void	move_a_to_b(int fd, t_stack *stack_a, t_stack *stack_b, int *op_count);
void	move_b_to_a(int fd, t_stack *stack_a, t_stack *stack_b, int *op_count);


// Stack reading and validating:
int	stack_read(int ac, char **av, t_stack *stack);
int	stack_check_sorted(t_stack stack_a);


int	throw_error_push_swap(int error_nr);

#endif
