/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:29:41 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/06 11:49:18 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack stack)
{
	size_t	size;
	t_snode	*current;

	if (!stack.top)
		return (0);
	size = 1;
	current = stack.top;
	while (current->next)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	stack_find_val(t_stack stack, int new_val)
{
	int		index;
	t_snode	*current;

	index = 0;
	current = stack.top;
	while (current)
	{
		if (current->val == new_val)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	stack_reset(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
	stack->minind = -1;
	stack->maxind = -1;
}

void	snode_reset(t_snode *snode)
{
	snode->val = 0;
	snode->index = -1;
	snode->next = NULL;
}

void	stack_update(t_stack *stack)
{
	int		ind;
	t_snode	*cur;
	t_snode	*min;
	t_snode	*max;

	if (!stack->top)
	{
		stack_reset(stack);
		return ;
	}
	ind = 0;
	cur = stack->top;
	min = cur;
	max = cur;
	while (cur)
	{
		if (cur->val < min->val)
			min = cur;
		if (cur->val > max->val)
			max = cur;
		cur->index = ind++;
		cur = cur->next;
	}
	stack->minind = min->index;
	stack->maxind = max->index;
}
