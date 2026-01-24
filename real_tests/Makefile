NAME = myapp

TESTS = run_tests

SRCS_TESTS_DIR = tests
BUILD_DIR_TESTS = $(SRCS_TESTS_DIR)/build

FILES_TESTS = \
	main.c \
	strlen/00_launcher.c \
	strlen/01_basic_test.c \
	strlen/02_failed_test.c \
	strlen/03_segfault_test.c \
	strlen/04_buserror_test.c

SRCS_TESTS = $(addprefix $(SRCS_TESTS_DIR)/, $(FILES_TESTS))
OBJS_TESTS := $(patsubst %.c, $(BUILD_DIR_TESTS)/%.o, $(FILES_TESTS))
DEPS_TESTS := $(patsubst %.c, $(BUILD_DIR_TESTS)/%.d, $(FILES_TESTS))

LIBUNIT_DIR = ..
LIBUNIT_FILE = libunit.a
LIBUNIT = $(LIBUNIT_DIR)/$(LIBUNIT_FILE)

INCLUDES_DIR = ./includes 
INCLUDES_LIBUNIT_DIR = ../includes

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(INCLUDES_LIBUNIT_DIR)
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re debug

all: $(TESTS)

debug: CFLAGS += -g -O0 -DDEBUG
debug: fclean $(TESTS)

$(TESTS): $(OBJS_TESTS) $(LIBUNIT)
	$(CC) $^  -o $@ 

$(LIBUNIT):
	$(MAKE) -C $(LIBUNIT_DIR)

$(BUILD_DIR_TESTS)/%.o: $(SRCS_TESTS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rfv $(BUILD_DIR_TESTS)

fclean: clean
	rm -f $(TESTS)

re: fclean all
