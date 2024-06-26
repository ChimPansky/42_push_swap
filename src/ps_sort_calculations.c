/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:19:50 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/17 15:22:58 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return distance from top position:
// distance < 0: rotate down
// distance > 0: rotate up
int	get_top_distance(size_t stack_size, int index)
{
	if (index > (int)stack_size / 2)
		return (index - (int)stack_size);
	return (index);
}

// used when pushing nodes from stack_a to stack_b:
// for a given node in stack_a find index of target node in stack_b
// target node means it has the next smaller value compared to node in a.
// if there are no smaller values in b then the target is the
// largest value (think of a circle)
int	find_target_b(t_stack *stack_b, int val_a)
{
	t_snode	*target_b;
	t_snode	*cur_b;

	target_b = NULL;
	cur_b = stack_b->top;
	while (cur_b)
	{
		if (cur_b->val < val_a && (!target_b || target_b->val < cur_b->val))
			target_b = cur_b;
		cur_b = cur_b->next;
	}
	if (!target_b)
		return (stack_b->maxind);
	return (target_b->index);
}

// used when pushing nodes from stack_b to stack_a:
// for the current top node in stack_b find index of target node in stack_a
// target node means it has the next larger value compared to node in b.
// if there are no larger values in a then the target is the
// smallest value (think of a circle)
int	find_target_a(t_stack *stack_a, int val_b)
{
	t_snode	*target_a;
	t_snode	*cur_a;

	target_a = NULL;
	cur_a = stack_a->top;
	while (cur_a)
	{
		if (cur_a->val > val_b && (!target_a || target_a->val > cur_a->val))
			target_a = cur_a;
		cur_a = cur_a->next;
	}
	if (!target_a)
		return (stack_a->minind);
	return (target_a->index);
}

// helper function for calc_rotation_cost below
static void	update_rotation_data(
	int *rot_data, int dist_a, int dist_b, int cost)
{
	if (rot_data[0] == 0 || (cost < rot_data[3]))
	{
		rot_data[0] = 1;
		rot_data[1] = dist_a;
		rot_data[2] = dist_b;
		rot_data[3] = cost;
	}
}

// called when pushing nodes from stack_a to stack_b:
// for every node in stack_a calculate how many operations it would take to
// rotate current node as well as target node to top of both stacks
// rotation_data[0]: reset-flag: 0...beginning of calculation -> initialize...
// rotation_data[1]: best stack_a index
// rotation_data[2]: best stack_b index
// rotation_data[3]: lowest number of ops to bring nodes to top of a and b
void	calc_rotation_cost(
	t_stack *stack_a, t_stack *stack_b, t_snode *cur_a, int *rot_cost)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = cur_a->index;
	rb = find_target_b(stack_b, cur_a->val);
	rra = ft_iif_int(ra, ra - (int)stack_a->size, ra);
	rrb = ft_iif_int(rb, rb - (int)stack_b->size, rb);
	update_rotation_data(rot_cost, ra, rb, ft_max(ra, rb));
	update_rotation_data(rot_cost, rra, rrb, ft_max(ft_abs(rra), ft_abs(rrb)));
	update_rotation_data(rot_cost, ra, rrb, ra + ft_abs(rrb));
	update_rotation_data(rot_cost, rra, rb, ft_abs(rra) + rb);
}
