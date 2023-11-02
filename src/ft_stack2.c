/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:42:58 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/02 12:38:36 by tkasbari         ###   ########.fr       */
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

t_snode	*stack_pop(t_stack *stack)
{
	t_snode	*popee;

	popee = stack->top;
	if (popee)
	{
		stack->top = popee->next;
		popee->next = NULL;
		stack->size--;
	}
	return (popee);
}

t_snode	*stack_bottom(t_stack *stack)
{
	t_snode	*last;

	last = stack->top;
	while (last && last->next)
		last = last->next;
	return (last);
}

void	stack_clear(t_stack *stack)
{
	t_snode	*current;
	t_snode	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		stack_snode_del(current);
		current = next;
	}
	stack_reset(stack);
}

void	stack_snode_del(t_snode *snode)
{
	if (snode)
	{
		free(snode);
		snode = NULL;
	}
}

void	stack_print(t_stack stack)
{
	t_snode	*current;

	current = stack.top;
	ft_printf("|-------\n");
	if (!current)
		ft_printf("empty\n");
	while (current)
	{
		ft_printf("%7d\n", current->val);
		current = current->next;
	}
	ft_printf("-------|\n");
	ft_printf("stack_size: %d\n", stack.size);
}

void	stacks_print(t_stack stack_a, t_stack stack_b)
{
	t_snode	*snode_a;
	t_snode	*snode_b;

	snode_a = stack_a.top;
	snode_b = stack_b.top;
	while (snode_a || snode_b)
	{
		if (snode_a)
		{
			ft_printf("|%6d", snode_a->val);
			snode_a = snode_a->next;
		}
		else
			ft_printf("|%6s", "");
		ft_printf("|");
		if (snode_b)
		{
			ft_printf("%6d|\n", snode_b->val);
			snode_b = snode_b->next;
		}
		else
			ft_printf("%6s|\n", "");
	}
	ft_printf("---------------\n");
	ft_printf("%s:%4d |%s:%4d\n", "a", stack_a.size, "b", stack_b.size);
}
