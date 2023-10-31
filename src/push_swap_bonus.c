/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:43:40 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/30 16:03:24 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*command;

	if (ac < 2)
		return (0);
	stack_a.top = NULL;
	stack_b.top = NULL;
	if (!stack_read(ac, av, &stack_a))
		return (1);
	stacks_print(stack_a, stack_b);
	ft_dprintf(1, "STDIN_FILENO: %d\n", STDIN_FILENO);
	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		if (!stack_execute_command(command, &stack_a, &stack_b))
			return (throw_error_push_swap(1) && 1);
		stacks_print(stack_a, stack_b);
		free(command);
		command = get_next_line(STDIN_FILENO);
	}
	if (stack_check_sorted(stack_a) && !stack_b.top)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
