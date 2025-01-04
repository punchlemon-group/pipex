.PHONY: all clean fclean re val norm
NAME = pipex

LIBFT_DIR = libft
LIBFT_A = libft.a

INCLUDE_DIR = include
SRCS_DIR = srcs
OUT_DIR = out

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

SRCS = \
$(addsuffix .c, \
	$(addprefix $(SRCS_DIR)/, \
		env \
		main \
	) \
) \

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

NPD_FLAG = --no-print-directory

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I/usr/$(INCLUDE_DIR) -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/$(INCLUDE_DIR)
LFLAGS = -L$(LIBFT_DIR) -lft
VFLAGS = \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-fds=yes \

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT_A) | $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

$(LIBFT_DIR)/$(LIBFT_A):
	@make $(NPD_FLAG) -C $(LIBFT_DIR) extend

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@make $(NPD_FLAG) -C $(LIBFT_DIR) clean
	@$(RM) -r $(OUT_DIR)

fclean: clean
	@$(RM) $(LIBFT_DIR)/$(LIBFT_A)
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all

de:
	@clear
	@make $(NPD_FLAG) re
	@./$(NAME)

VALGRIND_LOG = valgrind.log

val:
	@clear
	@make $(NPD_FLAG) re
	@valgrind $(VFLAGS) ./$(NAME) 2> $(VALGRIND_LOG)

norm:
	@$(call check_norminette, $(LIBFT_DIR))
	@$(call check_norminette, $(SRCS_DIR))
	@$(call check_norminette, $(INCLUDE_DIR))

define ok
	echo $1"$(GREEN)OK$(RESET)"
endef

define check_norminette
	@if norminette $1 | grep -q Error; then \
		norminette $1 | grep Error; \
	else \
		$(call ok, $1": "); \
	fi
endef
