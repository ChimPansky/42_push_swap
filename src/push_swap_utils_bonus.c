/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:49:12 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/30 15:58:53 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
int	stack_execute_command(char *command, t_stack *stack_a, t_stack *stack_b)
{
	int	operation_count;

	operation_count = 0;
	ft_str_chr_replace(command, '\n', '\0');
	if (!ft_strncmp(command, "sa", 3) || !ft_strncmp(command, "ss", 3))
		operation_count += stack_swap(stack_a);
	if (!ft_strncmp(command, "sb", 3) || !ft_strncmp(command, "ss", 3))
		operation_count += stack_swap(stack_b);
	if (!ft_strncmp(command, "pa", 3))
		operation_count += stack_transfer_top(stack_b, stack_a);
	if (!ft_strncmp(command, "pb", 3))
		operation_count += stack_transfer_top(stack_a, stack_b);
	if (!ft_strncmp(command, "ra", 3) || !ft_strncmp(command, "rr", 3))
		operation_count += stack_rotate_up(stack_a);
	if (!ft_strncmp(command, "rb", 3) || !ft_strncmp(command, "rr", 3))
		operation_count += stack_rotate_up(stack_b);
	if (!ft_strncmp(command, "rra", 4) || !ft_strncmp(command, "rrr", 4))
		operation_count += stack_rotate_down(stack_a);
	if (!ft_strncmp(command, "rrb", 4) || !ft_strncmp(command, "rrr", 4))
		operation_count += stack_rotate_down(stack_b);
	return (operation_count);
}

