NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SOURCE_DIR = src/
INCLUDE_DIR = include/
LIBFT_DIR = libft/
LIBFT_NAME = libft.a
HEADER = $(INCLUDE_DIR)push_swap.h

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

SRC_FILES = push_swap

SRC = $(addsuffix .c, $(addprefix $(SOURCE_DIR),$(SRC_FILES)))

OBJ = $(SRC:.c=.o)

all: make_libft $(NAME)

make_libft:
	make -C $(LIBFT_DIR)

# Fix problem when modifying libft source files and then calling make push_swap...
$(NAME): $(LIBFT_NAME) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_NAME) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

$(LIBFT_NAME): $(LIBFT_DIR)$(LIBFT_NAME)
	cp $(LIBFT_DIR)$(LIBFT_NAME) ./$(LIBFT_NAME)

$(LIBFT_DIR)$(LIBFT_NAME): make_libft

bonus: all

%.o : %.c $(HEADER)
	$(CC) -I $(INCLUDE_DIR) $(CFLAGS) -g -c $< -o $@

clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT_NAME)

re: fclean all

.PHONY: all make_libft clean fclean re bonus
