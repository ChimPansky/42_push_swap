NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SOURCE_DIR = src/
INCLUDE_DIR = include/
LIBFT_DIR = libft/
LIBFT_NAME = libft.a
HEADER = $(INCLUDE_DIR)push_swap.h
HEADER_BONUS = $(INCLUDE_DIR)push_swap_bonus.h


#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES = push_swap ps_operations ps_sorting ps_utils ft_stack1 ft_stack2

SRC_FILES_BONUS = push_swap_bonus ps_operations ps_sorting ps_utils ft_stack1 ft_stack2

SRC = $(addsuffix .c, $(addprefix $(SOURCE_DIR),$(SRC_FILES)))

SRC_BONUS = $(addsuffix .c, $(addprefix $(SOURCE_DIR),$(SRC_FILES_BONUS)))

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: make_libft $(NAME)

make_libft:
	make -C $(LIBFT_DIR)

# Fix problem when modifying libft source files and then calling make push_swap...
$(NAME): $(LIBFT_NAME) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_NAME) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

$(NAME_BONUS): $(LIBFT_NAME) $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_NAME) -o $(NAME_BONUS)
	@echo "$(GREEN)Executable $(NAME_BONUS) created!$(DEF_COLOR)"

$(LIBFT_NAME): $(LIBFT_DIR)$(LIBFT_NAME)
	cp $(LIBFT_DIR)$(LIBFT_NAME) ./$(LIBFT_NAME)

$(LIBFT_DIR)$(LIBFT_NAME): make_libft

bonus: $(NAME_BONUS)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) -I $(INCLUDE_DIR) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(LIBFT_NAME)

re: fclean all

.PHONY: all make_libft clean fclean re bonus
