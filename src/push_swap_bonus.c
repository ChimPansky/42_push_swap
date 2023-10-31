/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:43:40 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/31 15:48:09 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*command;
	int	op_count;

	op_count = 0;
	if (ac < 2)
		return (0);
	stack_a.top = NULL;
	stack_b.top = NULL;
	if (!stack_read(ac, av, &stack_a))
		return (1);
	stacks_print(stack_a, stack_b);
	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		if (!stack_execute_command(command, &op_count, &stack_a, &stack_b))
			return (throw_error_push_swap(1) && 1);
		stacks_print(stack_a, stack_b);
		free(command);
		command = get_next_line(STDIN_FILENO);
	}
	if (stack_check_sorted(stack_a) && !stack_b.top)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("%d Operation(s)\n", op_count);
	return (0);
}
