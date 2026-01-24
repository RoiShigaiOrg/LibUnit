NAME = libunit.a

BUILD_DIR = build
SRCS_DIR = src

FILES = load_test.c \
		launch_test.c

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(FILES))
DEPS := $(patsubst %.c, $(BUILD_DIR)/%.d, $(FILES))

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT_FILE = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_FILE)

INCLUDES_DIR = includes

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES_DIR)
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re debug

all: $(NAME)

bonus: $(BONUS)

debug: CFLAGS += -g -O0 -DDEBUG
debug: fclean $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $< $@
	ar -rcs $@ $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

norm: $(SRCS)
	@echo ⏳ Running norminette...
	@norminette -R CheckForbiddenHeader $(SRCS_DIR) $(INCLUDES_DIR) $(LIBFT_DIR)
	@echo ✅ Norminette passed!

clean:
	rm -rfv $(BUILD_DIR) $(TESTS_BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -fv $(TESTS_BIN)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
