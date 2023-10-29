#include "libft.h"
#include "push_swap.h"

int	main(void)
{

	//ft_putstr_fd(ft_strchr("abc\ndef", 'x'), 1);
	// ft_printf("test\n");
	// t_stack	my_stack;

	// my_stack.top = NULL;
	// stack_print(my_stack);
	// ft_print_memory(my_stack.top, 20);
	// stack_push_bot_val(&my_stack, 42);
	// stack_print(my_stack);
	// ft_print_memory(my_stack.top, 20);

	// char *s = "ABCdalsfn";
	// ft_print_memory(s, 9);

	int	test[10];
	int	ret;

	ret = ft_str_isint("123", &test[1]);
	ft_printf("is_int: %d\n", ret);
	ft_printf("int: %d\n", test[1]);

	return (0);
}
