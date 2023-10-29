/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:29:41 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/28 16:52:53 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stack_peek(t_snode snode)
{
	if (!snode.val)
		return (0);
	return (snode.val);
}

int	stack_push_top_node(t_stack *stack, t_snode *snode)
{
	if (!snode)
		return (0);
	snode->next = stack->top;
	stack->top = snode;
	return (1);
}

int	stack_push_top_val(t_stack *stack, int val)
{
	t_snode	*new;

	new = (t_snode *)malloc(sizeof(t_snode *));
	if (!new)
		return (0);
	new->val = val;
	new->next = NULL;
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
	return (1);
}

int	stack_push_bot_val(t_stack *stack, int val)
{
	t_snode	*new;

	new = (t_snode *)malloc(sizeof(t_snode *));
	if (!new)
		return (0);
	new->val = val;
	new->next = NULL;
	stack_push_bot_node(stack, new);
	return (1);
}
