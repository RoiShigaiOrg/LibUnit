EXEC= libunit.a

BUILD_DIR = build
SRCS_FILES = unit_test.c
SRCS_DIR = src

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(FILES))
DEPS := $(patsubst %.c, $(BUILD_DIR)/%.d, $(FILES))

LIBFTPRINTF_DIR = libftprintf
LIBFTPRINTF_FILE = libftprintf.a
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_FILE)

INCLUDES_DIR = includes

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES_DIR)
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re debug

all: $(NAME)

bonus: $(BONUS)

debug: CFLAGS += -g -O0 -DDEBUG
debug: fclean $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $^ -o $@ 

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

norm: $(SRCS)
	@echo ⏳ Running norminette...
	@norminette -R CheckForbiddenHeader $(SRCS_DIR) $(INCLUDES_DIR) $(LIBFTPRINTF_DIR)
	@echo ✅ Norminette passed!

clean:
	rm -rfv $(BUILD_DIR) $(TESTS_BUILD_DIR)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -fv $(TESTS_BIN)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all
