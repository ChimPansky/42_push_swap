/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:43:40 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/29 22:29:50 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

 int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*command;

	if (ac < 2)
		return (0);
	stack_a.top = NULL;
	stack_b.top = NULL;
	if (!read_stack(ac, av, &stack_a))
		return (1);
	stacks_print(stack_a, stack_b);
	command = read_stack_command();
	while (command)
	{
		if (ft_strnstr("*sa*sb*ss*pa*pb*ra*rb*rr*rra*rrb*rrr*", /////////////////////command, 50)
		execute_stack_command(command);
		command = read_stack_command();
	}
	if (!check_stack_sorted(stack_a))

	if (!read_commands( &stack_a))
		return (1);


	return (0);
}
