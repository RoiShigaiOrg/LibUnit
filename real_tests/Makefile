NAME = tests

BUILD_DIR = build
SRCS_DIR = .

FILES = \
	main.c \
	strlen/00_launcher.c \
	strlen/01_basic_test.c \
	strlen/02_failed_test.c

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(FILES))
DEPS := $(patsubst %.c, $(BUILD_DIR)/%.d, $(FILES))

LIBUNIT_DIR = ..
LIBUNIT_FILE = libunit.a
LIBUNIT = $(LIBUNIT_DIR)/$(LIBUNIT_FILE)

INCLUDES_DIR = .
INCLUDES_LIBUNIT_DIR = ../includes

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(INCLUDES_LIBUNIT_DIR)
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re debug

all: $(NAME)

debug: CFLAGS += -g -O0 -DDEBUG
debug: fclean $(NAME)

$(NAME): $(OBJS) $(LIBUNIT)
	$(CC) $^  -o $@ 

$(LIBUNIT):
	$(MAKE) -C $(LIBUNIT_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -rfv $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
