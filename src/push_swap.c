/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:08 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/06 17:29:30 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack_check_sorted(stack_a))
	{
		stack_clear(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
