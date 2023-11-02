/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:29:41 by tkasbari          #+#    #+#             */
/*   Updated: 2023/11/02 15:59:43 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_peek(t_snode snode)
{
	if (!snode.val)
		return (0);
	return (snode.val);
}

void	stack_reset(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
	stack->minval = 0;
	stack->maxval = 0;
}

void	snode_reset(t_snode *snode)
{
	snode->val = 0;
	snode->index = 0;
	snode->target = NULL;
	snode->next = NULL;
}

void	stack_update(t_stack *stack)
{
	size_t ind;
	t_snode	*cur;
	t_snode	*min;
	t_snode	*max;

	if (!stack->top)
		stack_reset(stack);
	ind = 0;
	cur = stack->top;
	while (cur)
	{
		cur->index = ind;
		if (cur == stack->top)
		{
			min = cur;
			max = cur;
		}
		else
		{
			if (cur->val < min->val)
				min = cur;
			if (cur->val > max->val)
				max = cur;
		}
		ind++;
		cur = cur->next;
	}
	stack->minval = min->val;
	stack->minind = min->index;
	stack->maxval = max->val;
	stack->maxind = max->index;
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
