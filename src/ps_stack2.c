/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:42:58 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/06 11:48:20 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_push_top_node(t_stack *stack, t_snode *snode)
{
	if (!snode)
		return (0);
	snode->next = stack->top;
	stack->top = snode;
	stack->size++;
	return (1);
}

int	stack_push_top_val(t_stack *stack, int val)
{
	t_snode	*new;

	new = (t_snode *)malloc(sizeof(t_snode));
	if (!new)
		return (0);
	snode_reset(new);
	new->val = val;
	stack_push_top_node(stack, new);
	return (1);
}

int	stack_push_bot_node(t_stack *stack, t_snode *snode)
{
	if (!snode)
		return (0);
	if (!stack->top)
		stack->top = snode;
	else
		stack_bottom(stack)->next = snode;
	stack->size++;
	return (1);
}

int	stack_push_bot_val(t_stack *stack, int val)
{
	t_snode	*new;

	new = (t_snode *)malloc(sizeof(t_snode));
	if (!new)
		return (0);
	snode_reset(new);
	new->val = val;
	stack_push_bot_node(stack, new);
	return (1);
}
