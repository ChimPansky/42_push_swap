NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
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

COMMON_FILES = ps_stack1 ps_stack2 ps_stack3 ps_utils ps_operations

PS_FILES = push_swap ps_sorting ps_sort_calculations

BONUS_FILES = push_swap_bonus

SRC = $(addsuffix .c, $(addprefix $(SOURCE_DIR),$(COMMON_FILES) $(PS_FILES)))

SRC_BONUS = $(addsuffix .c, $(addprefix $(SOURCE_DIR),$(COMMON_FILES) $(BONUS_FILES)))

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:
	make libft
	make $(NAME)
	make $(NAME_BONUS)

libft:
	make -C $(LIBFT_DIR)

$(LIBFT_DIR)$(LIBFT_NAME):
	make libft

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

$(NAME_BONUS): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME_BONUS)
	@echo "$(GREEN)Executable $(NAME_BONUS) created!$(DEF_COLOR)"

bonus: $(NAME_BONUS)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) -I $(INCLUDE_DIR) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(LIBFT_DIR)$(LIBFT_NAME) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all libft bonus clean fclean re
