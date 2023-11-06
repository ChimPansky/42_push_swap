/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:29:13 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/06 10:37:38 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find a pair of nodes in stack_a and stack_b that require the least amount of
// operations to rotate top and be pushed into the correct position in
// stack_b (descending order). Rotate both nodes to the top and execute "pb"
// rotation_cost[0]: reset-flag: 0...beginning of calculation -> initialize
// rotation_cost[1]: best stack_a index to rotate top
// rotation_cost[2]: best stack_b index to rotate top
// rotation_cost[3]: best(lowest) number of ops to bring nodes to top of a and b
void	push_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_snode	*cur_a;
	int		rotation_cost[4];

	if (stack_b->size > 1)
	{
		stack_update(stack_a);
		stack_update(stack_b);
		cur_a = stack_a->top;
		rotation_cost[0] = 0;
		while (cur_a)
		{
			calc_rotation_cost(stack_a, stack_b, cur_a, rotation_cost);
			cur_a = cur_a->next;
			if (rotation_cost[3] < 2)
				break ;
		}
		if (rotation_cost[1] || rotation_cost[2])
			rotate_elements_top(
				stack_a, stack_b, rotation_cost[1], rotation_cost[2]);
	}
	stack_execute_op("pb", stack_a, stack_b, 1);
}

// Push current node on top of stack_b into correct position in
// stack_a (ascending order). Rotate target node in stack_a to top and then "pa"
void	push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	target_index_a;
	int	target_distance_a;

	stack_update(stack_a);
	stack_update(stack_b);
	target_index_a = find_target_a(stack_a, stack_b->top->val);
	target_distance_a = get_top_distance(stack_a->size, target_index_a);
	rotate_elements_top(stack_a, stack_b, target_distance_a, 0);
	stack_execute_op("pa", stack_a, stack_b, 1);
}

// Rotate stack_a and/or stack_b: distances indicate the relative position of
// nodes(elements) that need to come to the top.
// distance: 0... element alrdy at top;
//			<0... element not at top and reverse down (ra/rb) is quickest
//			>0... element not at top and rotate up (rra/rrb) is quickest
void	rotate_elements_top(t_stack *stack_a, t_stack *stack_b,
		int distance_a, int distance_b)
{
	while (distance_a != 0 || distance_b != 0)
	{
		if (distance_a < 0 && distance_b < 0)
			stack_execute_op("rrr", stack_a, stack_b, 1);
		else if (distance_a > 0 && distance_b > 0)
			stack_execute_op("rr", stack_a, stack_b, 1);
		else
		{
			if (distance_a < 0)
				stack_execute_op("rra", stack_a, stack_b, 1);
			if (distance_a > 0)
				stack_execute_op("ra", stack_a, stack_b, 1);
			if (distance_b < 0)
				stack_execute_op("rrb", stack_a, stack_b, 1);
			if (distance_b > 0)
				stack_execute_op("rb", stack_a, stack_b, 1);
		}
		if (distance_a)
			distance_a += ft_iif_int(distance_a < 0, 1, -1);
		if (distance_b)
			distance_b += ft_iif_int(distance_b < 0, 1, -1);
	}
}

void	sort_three_stack(t_stack *stack)
{
	int	val0;
	int	val1;
	int	val2;

	val0 = stack->top->val;
	val1 = stack->top->next->val;
	val2 = stack->top->next->next->val;
	if (val1 > val0 && val1 > val2)
		stack_execute_op("rra", stack, NULL, 1);
	if (val0 > val1 && val0 > val2)
		stack_execute_op("ra", stack, NULL, 1);
	if ((val0 > val1 && val0 < val2))
		stack_execute_op("sa", stack, NULL, 1);
	if (stack_check_sorted(*stack))
		return ;
	sort_three_stack(stack);
}

//	basic idea: push all nodes (except for the last 3) from stack_a to stack_b
// in reverse order; then sort stack_a (max 2 operations) and push back nodes
// from stack_b to stack_a while making sure stack_a is in the correct
// position. in the end: rotate minimum value in stack_a to the top
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		stack_execute_op("sa", stack_a, NULL, 1);
		return ;
	}
	if (stack_a->size == 3)
	{
		sort_three_stack(stack_a);
		return ;
	}
	while (stack_a->size > 3)
		push_a_to_b(stack_a, stack_b);
	sort_three_stack(stack_a);
	stack_update(stack_b);
	rotate_elements_top(stack_a, stack_b, 0,
		get_top_distance(stack_b->size, stack_b->maxind));
	while (stack_b->size > 0)
		push_b_to_a(stack_a, stack_b);
	stack_update(stack_a);
	rotate_elements_top(stack_a, stack_b,
		get_top_distance(stack_a->size, stack_a->minind), 0);
}
