/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:40:07 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/28 20:04:44 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>	// variadic arguments in Printf
# include <limits.h>

// Helper Functions
int		ft_isspace(char c);
size_t	ft_strlen(const char	*s);

// Mandatory Part I - Libc Functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memset(void	*s, int c, size_t n);
void	ft_bzero(void	*s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memrchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);

// Mandatory Part II - Additional Functions:
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Libft Bonus:
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Libft Various Additions:
void	*ft_print_memory_width(void *addr, size_t size, size_t wdth);
void	*ft_print_memory(void *addr, size_t size);
int		ft_str_isnum(char *c);
int		ft_str_isint(char *c, int *target);

// Libft Additions for Printf:
size_t	ft_get_int_order_base(size_t nb, size_t base_len);
char	*ft_itoa_base_signed(int n, char *base);
char	*ft_itoa_base_unsigned(size_t n, char *base);
char	*ft_strreplicate(char c, size_t len);
char	*ft_strlpad(const char *s, char cpad, size_t target_size);
char	*ft_strrpad(const char *s, char cpad, size_t target_size);
char	*ft_strlpad_free(char *s, char cpad, size_t target_size, int to_free);
char	*ft_strrpad_free(char *s, char cpad, size_t target_size, int to_free);
char	*ft_strjoin_free(char *s1, char *s2, int to_free);
char	*ft_substr_free(char *s, unsigned int start, size_t len, int to_free);
int		ft_iif_int(int condition, int true_val, int false_val);
void	*ft_iif_ptr(int condition, void *true_val, void *false_val);
void	*ft_iif_ptr_f(int cond, char *(*f)(char const *), void *v1, void *v2);

// Printf Additions (Put into separate header?)
# define S_FLAGS "#0- +"
# define S_CONVERSIONS "csdiupxX"
# define S_BASE_U "0123456789"
# define S_BASE_HEX "0123456789abcdef"
# define S_BASE_HEXL "0123456789ABCDEF"

enum e_flags
{
	F_HASH = 1,
	F_ZERO = 2,
	F_MINUS = 4,
	F_SPACE = 8,
	F_PLUS = 16,
	F_PRECISION = 32,
	F_MIN_WIDTH = 64
};

typedef struct s_format
{
	int		flags;
	size_t	width;
	int		prec;
	char	type;
}			t_format;

int		ft_printf(const char *format, ...);
int		ft_printf_fd(int fd, const char *format, va_list args);
int		output_percent(int fd, const char **format);
int		output_conversion(int fd, t_format conf, va_list args);
int		output_c(int fd, t_format conf, va_list args);
int		output_regular(int fd, const char **format);
int		set_config(const char **format, t_format *conf);
char	*convert_diuxxp(char conv, va_list args);
char	*manipulate_s(char	*s, t_format conf);
char	*add_prefix(char *s, char *pre);
char	*pad_negative(char *s, char cpad, size_t width, int to_free);
char	*apply_precision_s(char *s, int prec);

// Get Next Line Additions (put in separate header?):
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

typedef struct s_buffer
{
	char	*cont;
	ssize_t	len;
	ssize_t	last_read;
}				t_buffer;

void	ft_free_and_null(void **ptr);
char	*get_next_line(int fd);

// Libft Additions for Stacks (Pushswap):
typedef struct s_stack_node
{
	int	val;
	struct s_stack_node *next;

}			t_snode;

typedef struct s_stack
{
	t_snode	*top;
}			t_stack;

size_t	stack_size(t_stack stack);
int		stack_peek(t_snode snode);
int		stack_push_top_val(t_stack *stack, int val);
int		stack_push_bot_val(t_stack *stack, int val);
int		stack_push_top_node(t_stack *stack, t_snode *snode);
int		stack_push_bot_node(t_stack *stack, t_snode *snode);
t_snode	*stack_pop(t_stack *stack);
t_snode	*stack_bottom(t_stack *stack);

void	stack_print(t_stack stack);
void	stacks_print(t_stack stack_a, t_stack stack_b);


#endif
