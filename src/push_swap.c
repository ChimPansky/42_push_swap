/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:08 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/28 21:06:30 by tkasbari         ###   ########.fr       */
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
int	check_duplicates(int *number, int i)
{
	//....
	if (i || *number)
		return (1);
	return (1);
}

 int	main(int ac, char **av)
{
	int	i;
	t_stack	stack_a;
	t_stack	stack_b;
	int	numbers[ac - 1];

	if (ac < 2)
		return (0);
	i = 1;
	stack_a.top = NULL;
	stack_b.top = NULL;
	while (i < ac)
	{
		if (!ft_str_isint(av[i], &numbers[i]))
		{
			ft_printf("Error\n");
			return (1);
		}

		stack_push_bot_val(&stack_a, numbers[i]);
		i++;
	}
	stacks_print(stack_a, stack_b);
	return (0);

	// int	test[ac];
	// int	ret;

	// ret = ft_str_isint(av[1], &test[1]);
	// ft_printf("is_int: %d\n", ret);
	// ft_printf("int: %d\n", test[1]);
}
