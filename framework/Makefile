NAME = libunit.a

BUILD_DIR = build
SRCS_DIR = src

FILES = \
	load_test.c \
	launch_test.c \
	display.c \
	test_group.c \
	timeout.c \
	run_print_fct.c

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(FILES))
DEPS := $(patsubst %.c, $(BUILD_DIR)/%.d, $(FILES))

TESTS_DIR = ../tests
TESTS_BUILD_DIR = $(TESTS_DIR)/build
TESTS_BIN = $(TESTS_BUILD_DIR)/run_test

TESTS_FILES = \
	main.c \
	libunit/00_launcher.c \
	libunit/01_test_ok.c \
	libunit/02_test_ko.c \
	libunit/03_test_segfault.c \
	libunit/04_test_buserror.c \
	libunit/05_test_timeout.c \
	libunit/06_test_print_stdout_function.c \
	libunit/07_test_sigabort.c \
	libunit/08_test_sigfpe.c \
	libunit/09_test_sigpipe.c
TESTS_SRCS = $(addprefix $(TESTS_DIR)/, $(TESTS_FILES))
TESTS_OBJS := $(patsubst %.c, $(TESTS_BUILD_DIR)/%.o, $(TESTS_FILES))
TESTS_DEPS := $(patsubst %.c, $(TESTS_BUILD_DIR)/%.d, $(TESTS_FILES))

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT_FILE = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_FILE)

INCLUDES_DIR = includes
TESTS_INCLUDES_DIR = $(TESTS_DIR)/includes

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES_DIR)
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re debug test

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

$(TESTS_BUILD_DIR)/%.o: $(TESTS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -g -c $< -I$(TESTS_INCLUDES_DIR) -o $@

$(TESTS_BIN): $(OBJS) $(TESTS_OBJS) $(NAME)
	$(CC) -I$(TESTS_INCLUDES_DIR) $(TESTS_OBJS) $(NAME) -o $@

test: $(TESTS_BIN)
	@$<


norm: $(SRCS)
	@echo ⏳ Running norminette...
	@norminette -R CheckForbiddenHeader $(SRCS_DIR) $(INCLUDES_DIR) $(LIBFT_DIR)
	@echo ✅ Norminette passed!

clean:
	rm -rfv $(BUILD_DIR) $(TESTS_BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS) $(TESTS_DEPS)
