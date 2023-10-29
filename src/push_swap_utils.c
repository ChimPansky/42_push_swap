/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:38:32 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/29 22:01:50 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stack_swap(t_stack *stack)
{
	int	temp;

	if (!stack->top || !stack->top->next)
		return ;
	temp = stack->top->val;
	stack->top->val = stack->top->next->val;
	stack->top->next->val = temp;
}

void	stack_transfer_top(t_stack *src, t_stack *dst)
{
	t_snode	*popped;

	popped = stack_pop(src);
	if (popped)
		stack_push_top_node(dst, popped);
}
void	stack_rotate_up(t_stack *stack)
{
	t_snode	*temp;

	if (!stack->top || !stack->top->next)
		return ;
	temp = stack->top->next;
	stack_bottom(stack)->next = stack->top;
	stack->top->next = NULL;
	stack->top = temp;
}
void	stack_rotate_down(t_stack *stack)
{
	t_snode	*temp;
	t_snode	*second_last;

	if (!stack->top || !stack->top->next)
		return ;
	temp = stack->top;
	second_last = stack->top;
	while (second_last->next->next)
		second_last = second_last->next;
	stack->top = second_last->next;
	stack->top->next = temp;
	second_last->next = NULL;
}

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
int	read_stack(int ac, char **av, t_stack *stack)
{
	int	i;
	int	new_val;

	i = 1;
	while (i < ac)
	{
		if (!ft_str_isint(av[i], &new_val) || stack_find_val(*stack, new_val))
		{
			ft_printf("Error\n");
			return (0);
		}
		stack_push_bot_val(stack, new_val);
		i++;
	}
	return (1);
}
