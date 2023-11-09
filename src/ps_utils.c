/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:04:12 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/08 21:29:21 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splitted(char	**splitted)
{
	char	**to_free;

	if (!splitted)
		return ;
	to_free = splitted;
	while (*splitted)
	{
		free(*splitted);
		splitted++;
	}
	free(to_free);
}

// interpret program arguments as elements of stack to be sorted.
// for each argument check that it is an integer as well as no duplicate
int	stack_read(int ac, char **av, t_stack *stack)
{
	int		new_val;
	char	**splitted;
	char	**to_free;
	int		i;

	i = 1;
	while (i < ac)
	{
		splitted = ft_split(av[i++], ' ');
		to_free = splitted;
		while (splitted && *splitted)
		{
			if (!ft_str_isint(*splitted, &new_val)
				|| stack_find_val(*stack, new_val) != -1
				|| !stack_push_bot_val(stack, new_val))
			{
				stack_clear(stack);
				free_splitted(to_free);
				return (0);
			}
			splitted++;
		}
		free_splitted(to_free);
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

int	ps_throw_error(int error_nr)
{
	char	*err_msg;

	if (error_nr == 1)
		err_msg = "Error";
	else
		err_msg = "Unknown Error";
	ft_dprintf(STDERR_FILENO, "%s\n", err_msg);
	return (error_nr);
}
