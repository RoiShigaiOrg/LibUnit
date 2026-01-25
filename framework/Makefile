NAME = libunit.a
BONUS = libunit_bonus.a

BUILD_DIR = build
SRCS_DIR = src

FILES = \
	load_test.c \
	launch_test.c \
	display.c \
	test_group.c

FILES_BONUS = \
	load_test.c \
	launch_test_bonus.c \
	display_bonus.c \
	test_group.c \
	run_print_fct_bonus.c

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(FILES))
DEPS := $(patsubst %.c, $(BUILD_DIR)/%.d, $(FILES))

SRCS_BONUS = $(addprefix $(SRCS_DIR)/, $(FILES_BONUS))
OBJS_BONUS:= $(patsubst %.c, $(BUILD_DIR)/%.o, $(FILES_BONUS))
DEPS_BONUS := $(patsubst %.c, $(BUILD_DIR)/%.d, $(FILES_BONUS))

TESTS_DIR = ../tests
TESTS_BUILD_DIR = $(TESTS_DIR)/build
TESTS_BIN = $(TESTS_BUILD_DIR)/run_test
TESTS_BONUS_BIN = $(TESTS_BUILD_DIR)/run_test_bonus

TESTS_FILES = \
	main.c \
	libunit/00_launcher.c \
	libunit/01_test_ok.c \
	libunit/02_test_ko.c \
	libunit/03_test_segfault.c \
	libunit/04_test_buserror.c

TESTS_BONUS_FILES = \
	main.c \
	libunit/00_launcher_bonus.c \
	libunit/01_test_ok.c \
	libunit/02_test_ko.c \
	libunit/03_test_segfault.c \
	libunit/04_test_buserror.c \
	libunit/05_test_timeout_bonus.c \
	libunit/06_test_print_stdout_function_bonus.c \
	libunit/07_test_sigabort_bonus.c \
	libunit/08_test_sigfpe_bonus.c

TESTS_SRCS = $(addprefix $(TESTS_DIR)/, $(TESTS_FILES))
TESTS_OBJS := $(patsubst %.c, $(TESTS_BUILD_DIR)/%.o, $(TESTS_FILES))
TESTS_DEPS := $(patsubst %.c, $(TESTS_BUILD_DIR)/%.d, $(TESTS_FILES))

TESTS_BONUS_SRCS = $(addprefix $(TESTS_DIR)/, $(TESTS_BONUS_FILES))
TESTS_BONUS_OBJS := $(patsubst %.c, $(TESTS_BUILD_DIR)/%.o, $(TESTS_BONUS_FILES))
TESTS_BONUS_DEPS := $(patsubst %.c, $(TESTS_BUILD_DIR)/%.d, $(TESTS_BONUS_FILES))

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

$(BONUS): $(LIBFT) $(OBJS_BONUS)
	cp $< $@
	ar -rcs $@ $(OBJS_BONUS)

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

$(TESTS_BONUS_BIN): $(OBJS_BONUS) $(TESTS_BONUS_OBJS) $(BONUS)
	$(CC) -I$(TESTS_INCLUDES_DIR) $(TESTS_BONUS_OBJS) $(BONUS) -o $@

test: $(TESTS_BIN)
	@$<

test_bonus: $(TESTS_BONUS_BIN)
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

-include $(DEPS) $(TESTS_DEPS) $(DEPS_BONUS) $(TESTS_BONUS_DEPS)
