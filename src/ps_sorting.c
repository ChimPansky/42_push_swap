/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:29:13 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/03 13:00:43 by tkasbari         ###   ########.fr       */
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

size_t	find_target_ind_b(t_stack *stack_b, int val_a)
{
	t_snode	*target_b;
	t_snode	*cur_b;

	target_b = NULL;
	cur_b = stack_b->top;
	while(cur_b)
	{
		if (cur_b->val < val_a && (!target_b || target_b->val < cur_b->val))
			target_b = cur_b;
		cur_b = cur_b->next;
	}
	if (target_b)
		return (target_b->index);
	else
		return (stack_b->maxind);
}

void	move_a_to_b(t_stack *stack_a, t_stack *stack_b, int *op_count)
{
	t_snode	*cur_a;
	size_t	best_ind_a;
	size_t	best_ind_b;
	size_t	cur_ind_b;

	if (stack_b->size > 1)
	{
		stack_update(stack_a);
		stack_update(stack_b);
		cur_a = stack_a->top;
		while (cur_a)
		{
			cur_ind_b = find_target_ind_b(stack_b, cur_a->val);
			if (cur_a == stack_a->top
				|| ((cur_a->index + cur_ind_b) < (best_ind_a + best_ind_b)))
			{
				best_ind_a = cur_a->index;
				best_ind_b = cur_ind_b;
			}
			cur_a = cur_a->next;
		}
		snode_move_top(stack_a, stack_b, best_ind_a, best_ind_b, op_count);
	}
	print_and_execute("pb", stack_a, stack_b, op_count);
}

void	snode_move_top(t_stack *stack_a, t_stack *stack_b,
		int index_a, int index_b, int *op_count)
{
	if (index_a > ((int)stack_a->size / 2))
		index_a -= (int)stack_a->size;
	if (index_b > ((int)stack_b->size / 2))
		index_b -= (int)stack_b->size;
	while (index_a != 0 || index_b != 0)
	{
		if (index_a < 0 && index_b < 0)
		{
			print_and_execute("rrr", stack_a, stack_b, op_count);
			index_a++;
			index_b++;
		}
		else if (index_a > 0 && index_b > 0)
		{
			print_and_execute("rr", stack_a, stack_b, op_count);
			index_a--;
			index_b--;
		}
		else if (index_a < 0)
		{
			print_and_execute("rra", stack_a, stack_b, op_count);
			index_a++;
		}
		else if (index_a > 0)
		{
			print_and_execute("ra", stack_a, stack_b, op_count);
			index_a--;
		}
		else if (index_b < 0)
		{
			print_and_execute("rrb", stack_a, stack_b, op_count);
			index_b++;
		}
		else if (index_b > 0)
		{
			print_and_execute("rb", stack_a, stack_b, op_count);
			index_b--;
		}
	}
}

void	move_b_to_a(t_stack *stack_a, t_stack *stack_b, int *op_count)
{
	size_t	target_index;
	t_snode	*target_a;
	t_snode	*cur_a;

	stack_update(stack_a);
	stack_update(stack_b);
	target_a = NULL;
	cur_a = stack_a->top;
	while (cur_a)
	{
		if (cur_a->val > stack_b->top->val && (!target_a || target_a->val > cur_a->val))
				target_a = cur_a;
		cur_a = cur_a->next;
	}
	if (target_a)
		target_index = target_a->index;
	else
		target_index = stack_a->minind;
	snode_move_top(stack_a, stack_b, (int)target_index, 0, op_count);
	print_and_execute("pa", stack_a, stack_b, op_count);
}


void	print_and_execute(char *op, t_stack *stack_a,
	t_stack *stack_b, int *op_count)
{
	ft_dprintf(OPERATIONS_FD, op);
	ft_dprintf(OPERATIONS_FD, "\n");
	stack_execute_op(op, op_count, stack_a, stack_b, 0);
}

void	stack_three_sort(t_stack *stack, int *op_count)
{
 	int	val0;
	int	val1;
	int	val2;

	if (stack->size == 2)
	{
		print_and_execute("sa", stack, NULL, op_count);
		return ;
	}
	else
	{
		val0 = stack->top->val;
		val1 = stack->top->next->val;
		val2 = stack->top->next->next->val;
		if (val1 > val0 && val1 > val2)
			print_and_execute("rra", stack, NULL, op_count);
		if (val0 > val1 && val0 > val2)
			print_and_execute("ra", stack, NULL, op_count);
		if ((val0 > val1 && val0 < val2))
			print_and_execute("sa", stack, NULL, op_count);
		if (stack_check_sorted(*stack))
			return ;
		stack_three_sort(stack, op_count);
	}
}
