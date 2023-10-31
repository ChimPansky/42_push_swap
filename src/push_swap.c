/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:08 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/30 16:40:05 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 int	main(int ac, char **av)
{
	t_stack	stack_a;

	if (ac < 2)
		return (0);
	stack_a.top = NULL;
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
	stack_print(stack_a);
	ft_printf("here we go\n");
	stack_clear(&stack_a);
	stack_print(stack_a);
	// print commands to sort stack...
	//stacks_print(stack_a, stack_b);
	//stack_clear(&stack_a);
	return (0);
}
