/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:08 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/02 15:00:17 by tkasbari         ###   ########.fr       */
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
	stack_reset(&stack_b);
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
	stacks_print(stack_a, stack_b);
	ft_printf("here we go:\n");
	while (stack_a.size > 3)
	{
		move_a_to_b(OUTPUT_FD, &stack_a, &stack_b, &op_count);
		stacks_print(stack_a, stack_b);
	}
	stack_three_sort(OUTPUT_FD, &stack_a, &op_count);
	stacks_print(stack_a, stack_b);
	while (stack_b.size > 0)
		move_b_to_a(OUTPUT_FD, &stack_a, &stack_b, &op_count);
	//if (stack_b.size > 0)
		//move_b_to_a(OUTPUT_FD, &stack_a, &stack_b);

	stacks_print(stack_a, stack_b);
	ft_printf("op_count: %d\n", op_count);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
