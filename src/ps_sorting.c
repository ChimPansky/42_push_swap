/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:29:13 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/04 20:01:16 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_move_top_cost(t_stack stack, int index)
{
	if (index > ((int)stack.size / 2))
		return ((int)stack.size - index);
	else
		return (index);
}

int	find_target_ind_b(t_stack *stack_b, int val_a)
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
	if (!target_b)
		return (stack_b->maxind);
	return (target_b->index);
}

static int	get_rotation_distance(size_t stack_size, int index)
{
	if (index > (int)stack_size / 2)
		return (index - (int)stack_size);
	return (index);
}

static void	update_rotation_data(int *rot_data, int dist_a, int dist_b, int cost)
{
	if (cost < rot_data[2])
	{
		rot_data[0] = dist_a;
		rot_data[1] = dist_b;
		rot_data[2] = cost;
	}
}
// rotation_data[0]: best stack_a index
// rotation_data[1]: best stack_b index
// rotation_data[2]: number of operations to bring nodes at those indizes to top
// rotation_data[3]: number of operations to bring current nodes to the top
void	get_rotation_cost(t_stack *stack_a, t_stack *stack_b, t_snode *cur_a, int *rot_data)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = cur_a->index;
	rb = find_target_ind_b(stack_b, cur_a->val);
	rra = ft_iif_int(ra, ra - (int)stack_a->size, ra);
	rrb = ft_iif_int(rb, rb - (int)stack_b->size, rb);
	if (rot_data[0] == -1)
	{
		rot_data[0] = 0;
		rot_data[1] = get_rotation_distance(stack_b->size, rb);
		rot_data[2] = ft_abs(rot_data[1]);
	}
	else
	{
		update_rotation_data(rot_data, ra, rb, ft_max(ra, rb));
		update_rotation_data(rot_data, rra, rrb, ft_max(ft_abs(rra), ft_abs(rrb)));
		update_rotation_data(rot_data, ra, rrb, ra + ft_abs(rrb));
		update_rotation_data(rot_data, rra, rb, ft_abs(rra) + rb);
	}
}

void	push_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_snode	*cur_a;
	int		rotation_data[3];

	if (stack_b->size > 1)
	{
		stack_update(stack_a);
		stack_update(stack_b);
		cur_a = stack_a->top;
		while (cur_a)
		{
			rotation_data[0] = -1;
			get_rotation_cost(stack_a, stack_b, cur_a, rotation_data);
			cur_a = cur_a->next;
			if (rotation_data[2] < 2)
				break;
		}
		ft_printf("rotation_data: %d, %d, %d.\n", rotation_data[0], rotation_data[1],rotation_data[2]);
		if (rotation_data[0] || rotation_data[1])
			rotate_elements_top(stack_a, stack_b, rotation_data[0], rotation_data[1]);
	}
	print_and_execute("pb", stack_a, stack_b);
}

void	rotate_elements_top(t_stack *stack_a, t_stack *stack_b,
		int distance_a, int distance_b)
{

	while (distance_a != 0 || distance_b != 0)
	{
		if (distance_a < 0 && distance_b < 0)
		{
			print_and_execute("rrr", stack_a, stack_b);
			distance_a++;
			distance_b++;
		}
		else if (distance_a > 0 && distance_b > 0)
		{
			print_and_execute("rr", stack_a, stack_b);
			distance_a--;
			distance_b--;
		}
		else if (distance_a < 0)
		{
			print_and_execute("rra", stack_a, stack_b);
			distance_a++;
		}
		else if (distance_a > 0)
		{
			print_and_execute("ra", stack_a, stack_b);
			distance_a--;
		}
		else if (distance_b < 0)
		{
			print_and_execute("rrb", stack_a, stack_b);
			distance_b++;
		}
		else if (distance_b > 0)
		{
			print_and_execute("rb", stack_a, stack_b);
			distance_b--;
		}
	}
}

void	push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int		target_index;
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
		target_index = get_rotation_distance(stack_a->size, target_a->index);
	else
		target_index = get_rotation_distance(stack_a->size, stack_a->minind);
	rotate_elements_top(stack_a, stack_b, target_index, 0);
	print_and_execute("pa", stack_a, stack_b);
}

void	print_and_execute(char *op, t_stack *stack_a, t_stack *stack_b)
{
	ft_dprintf(OPERATIONS_FD, op);
	ft_dprintf(OPERATIONS_FD, "\n");
	stack_execute_op(op, stack_a, stack_b);
}

void	sort_three_stack(t_stack *stack)
{
 	int	val0;
	int	val1;
	int	val2;

	if (stack->size == 2)
	{
		print_and_execute("sa", stack, NULL);
		return ;
	}
	else
	{
		val0 = stack->top->val;
		val1 = stack->top->next->val;
		val2 = stack->top->next->next->val;
		if (val1 > val0 && val1 > val2)
			print_and_execute("rra", stack, NULL);
		if (val0 > val1 && val0 > val2)
			print_and_execute("ra", stack, NULL);
		if ((val0 > val1 && val0 < val2))
			print_and_execute("sa", stack, NULL);
		if (stack_check_sorted(*stack))
			return ;
		sort_three_stack(stack);
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		push_a_to_b(stack_a, stack_b);
	sort_three_stack(stack_a);
	while (stack_b->size > 0)
		push_b_to_a(stack_a, stack_b);
	stack_update(stack_a);
	rotate_elements_top(stack_a, stack_b,
		get_rotation_distance(stack_a->size, stack_a->minind), 0);
}
