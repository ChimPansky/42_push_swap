/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:04:12 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/02 12:48:26 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_find_val(t_stack stack, int new_val)
{
	t_snode	*current;

	current = stack.top;
	while (current)
	{
		if (current->val == new_val)
			return (1);
		current = current->next;
	}
	return (0);
}

int	stack_read(int ac, char **av, t_stack *stack)
{
	int	i;
	int	new_val;

	i = 1;
	while (i < ac)
	{
		if (!ft_str_isint(av[i], &new_val)
			|| stack_find_val(*stack, new_val)
			|| !stack_push_bot_val(stack, new_val))
			return (throw_error_push_swap(1) && 0);
		i++;
	}
	return (1);
}

int	stack_check_sorted(t_stack stack_a)
{
	t_snode	*snode_a;

	snode_a = stack_a.top;
	while (snode_a)
	{
		if (snode_a->next && snode_a->val > snode_a->next->val)
			return (0);
		snode_a = snode_a->next;
	}
	return (1);
}

int	throw_error_push_swap(int error_nr)
{
	char	*err_msg;
	if (error_nr == 1)
		err_msg = "Error";
	else
		err_msg = "Unknown Error";
	ft_dprintf(STDERR_FILENO, "%s\n", err_msg);
	return (error_nr);
}
