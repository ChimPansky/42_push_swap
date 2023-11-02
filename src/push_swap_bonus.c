/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:43:40 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/02 13:35:58 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*op;
	int	op_count;

	op_count = 0;
	if (ac < 2)
		return (0);
	stack_reset(&stack_a);
	stack_reset(&stack_b);
	if (!stack_read(ac, av, &stack_a))
		return (1);
	stacks_print(stack_a, stack_b);
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (!stack_execute_op(op, &op_count, &stack_a, &stack_b, 1))
			return (throw_error_push_swap(1) && 1);
		if (DISPLAY_INFO)
			stacks_print(stack_a, stack_b);
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	if (stack_check_sorted(stack_a) && !stack_b.top)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (DISPLAY_INFO)
		ft_printf("%d Operation(s)\n", op_count);
	return (0);
}
