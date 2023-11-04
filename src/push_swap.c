/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:08 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/03 11:32:09 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		op_count;

	if (ac < 2)
		return (0);
	stack_reset(&stack_a);
	op_count = 0;
	if (!stack_read(ac, av, &stack_a))
	{
		stack_clear(&stack_a);
		return (1);
	}
	if (stack_check_sorted(stack_a))
	{
		stack_clear(&stack_a);
		return (0);
	}
	stack_reset(&stack_b);
	while (stack_a.size > 3)
		move_a_to_b(&stack_a, &stack_b, &op_count);
	stack_three_sort(&stack_a, &op_count);
	while (stack_b.size > 0)
		move_b_to_a(&stack_a, &stack_b, &op_count);
	stack_update(&stack_a);
	snode_move_top(&stack_a, &stack_b, stack_a.minind, 0, &op_count);
	//stacks_print(stack_a, stack_b);
	//ft_printf("op_count: %d\n", op_count);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
