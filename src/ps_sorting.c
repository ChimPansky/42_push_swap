/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:29:13 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/02 16:20:15 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 int		get_move_top_cost(t_stack stack, size_t index)
{
	if (index > (stack.size / 2))
		return (stack.size - index);
	else
		return (index);
}

void	move_a_to_b(int fd, t_stack *stack_a, t_stack *stack_b, int *op_count)
{
	if (stack_b->size < 2)
		print_and_execute(fd, "pb", stack_a, stack_b, op_count);
}

void	snode_move_top(int fd, t_stack *stack_a, t_stack *stack_b, t_snode *snode)
{
	size_t	stack_size;

	if (!stack_a)
		stack_size = stack_b->size;
	else
		stack_size = stack_a->size;

	print_and_execute(fd, "sa", stack_a, stack_b, op_count);
}
void	move_b_to_a(int fd, t_stack *stack_a, t_stack *stack_b, int *op_count)
{
	size_t	target_index;
	t_snode	*target_a;

	stack_update(stack_a);
	target_a = NULL;
	cur_a = stack_a->top;
	while (cur_a)
	{
		if (cur_a->val > stack_b->top->val && (!target_a || target_a->val > cur_a->val))
				target_a = cur_a;
		index++;
		cur_a = cur_a->next;
	}
	if (target_a)
		target_index = target_a->index;
	else
		target_index = stack_a->maxind;
	snode_move_top(fd, stack_a, target_index);

	print_and_execute(fd, "pa", stack_a, stack_b, op_count);
}


void	print_and_execute(int fd, char *op, t_stack *stack_a,
	t_stack *stack_b, int *op_count)
{
	ft_dprintf(fd, op);
	ft_dprintf(fd, "\n");
	stack_execute_op(op, op_count, stack_a, stack_b, 0);
}

void	stack_three_sort(int fd, t_stack *stack, int *op_count)
{
 	int	val0;
	int	val1;
	int	val2;

	if (stack->size == 2)
	{
		print_and_execute(OUTPUT_FD, "sa", stack, NULL, op_count);
		return ;
	}
	else
	{
		val0 = stack->top->val;
		val1 = stack->top->next->val;
		val2 = stack->top->next->next->val;
		if (val1 > val0 && val1 > val2)
			print_and_execute(fd, "rra", stack, NULL, op_count);
		if (val0 > val1 && val0 > val2)
			print_and_execute(fd, "ra", stack, NULL, op_count);
		if ((val0 > val1 && val0 < val2))
			print_and_execute(fd, "sa", stack, NULL, op_count);
		if (stack_check_sorted(*stack))
			return ;
		stack_three_sort(fd, stack, op_count);
	}
}
