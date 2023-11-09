/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:43:40 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/09 15:20:18 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// if stack_execute_op fails:
// since we are stopping before GNL reached EOF last GNL did not return NULL,
// static buffer hasnt been cleared -> BUFFER_SIZE bytes still in use at exit
int	read_and_execute_ops(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		ft_str_chr_replace(op, '\n', '\0');
		if (!stack_execute_op(op, stack_a, stack_b, 0))
		{
			free(op);
			stack_clear(stack_a);
			stack_clear(stack_b);
			return (0);
		}
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	stack_reset(&stack_a);
	stack_reset(&stack_b);
	if (!stack_read(ac, av, &stack_a))
		return (ps_throw_error(1));
	if (!read_and_execute_ops(&stack_a, &stack_b))
		return (ps_throw_error(1));
	if (stack_check_sorted(stack_a) && !stack_b.top)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
