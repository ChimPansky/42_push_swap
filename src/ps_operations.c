/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:38:32 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/06 13:00:09 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_swap(t_stack *stack)
{
	int	temp;

	if (!stack->top || !stack->top->next)
		return (1);
	temp = stack->top->val;
	stack->top->val = stack->top->next->val;
	stack->top->next->val = temp;
	return (1);
}

int	stack_transfer_top(t_stack *src, t_stack *dst)
{
	t_snode	*popped;

	popped = stack_pop(src);
	if (popped)
		stack_push_top_node(dst, popped);
	return (1);
}

int	stack_rotate_up(t_stack *stack)
{
	t_snode	*temp;

	if (!stack->top || !stack->top->next)
		return (1);
	temp = stack->top->next;
	stack_bottom(stack)->next = stack->top;
	stack->top->next = NULL;
	stack->top = temp;
	return (1);
}

int	stack_rotate_down(t_stack *stack)
{
	t_snode	*temp;
	t_snode	*second_last;

	if (!stack->top || !stack->top->next)
		return (1);
	temp = stack->top;
	second_last = stack->top;
	while (second_last->next->next)
		second_last = second_last->next;
	stack->top = second_last->next;
	stack->top->next = temp;
	second_last->next = NULL;
	return (1);
}

// used in both push_swap and checker
// difference: push_swap executes and prints operation
//			   checker only executes operation
int	stack_execute_op(
	char *op, t_stack *stack_a, t_stack *stack_b, int print)
{
	int	op_valid;

	op_valid = 0;
	if (print)
		ft_dprintf(OPERATIONS_FD, "%s\n", op);
	if (!ft_strncmp(op, "sa", 3) || !ft_strncmp(op, "ss", 3))
		op_valid = stack_swap(stack_a);
	if (!ft_strncmp(op, "sb", 3) || !ft_strncmp(op, "ss", 3))
		op_valid = stack_swap(stack_b);
	if (!ft_strncmp(op, "pa", 3))
		op_valid = stack_transfer_top(stack_b, stack_a);
	if (!ft_strncmp(op, "pb", 3))
		op_valid = stack_transfer_top(stack_a, stack_b);
	if (!ft_strncmp(op, "ra", 3) || !ft_strncmp(op, "rr", 3))
		op_valid = stack_rotate_up(stack_a);
	if (!ft_strncmp(op, "rb", 3) || !ft_strncmp(op, "rr", 3))
		op_valid = stack_rotate_up(stack_b);
	if (!ft_strncmp(op, "rra", 4) || !ft_strncmp(op, "rrr", 4))
		op_valid = stack_rotate_down(stack_a);
	if (!ft_strncmp(op, "rrb", 4) || !ft_strncmp(op, "rrr", 4))
		op_valid = stack_rotate_down(stack_b);
	return (op_valid);
}
