CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

NAME = libft.a
TEST_BIN = run_test

INCLUDES=includes/
SRCS = ft_atoi.c \
	ft_itoa.c \
	ft_putnbr_fd.c \
	ft_strlcpy.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_memchr.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_memcmp.c \
	ft_split.c \
	ft_strmapi.c \
	ft_isalnum.c \
	ft_memcpy.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_isalpha.c \
	ft_memmove.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_isascii.c \
	ft_memset.c \
	ft_striteri.c \
	ft_strrchr.c \
	ft_isdigit.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_isprint.c \
	ft_putendl_fd.c \
	ft_strlcat.c \
	ft_substr.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	printf/args.c \
	printf/convert_base.c \
	printf/unsigned_convert_base.c \
	printf/flags2.c \
	printf/ft_printf.c
	
TESTS_SRCS = \
	tests/main.c \
	tests/ft_strlen/00_launcher.c \
	tests/ft_strlen/01_test_empty_string.c \
	tests/ft_strlen/02_test_normal_string.c \
	tests/ft_atoi/00_launcher.c \
	tests/ft_atoi/01_test_zero_value.c \
	tests/ft_atoi/02_test_positive_value.c \
	tests/ft_atoi/03_test_negative_value.c \
	tests/ft_atoi/04_test_valid_prefixes.c \
	tests/ft_atoi/05_test_invalid_prefixes.c
TESTS_OBJS = $(patsubst %.c, %.o, $(TESTS_SRCS))

HEADERS = $(INCLUDES)libft.h \
		  $(INCLUDES)ft_prinf.h

OBJS = $(SRCS:.c=.o)
TESTS_OBJS = $(TESTS_SRCS:.c=.o)

LIBUNIT = tests/libunit/libunit.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(TEST_BIN): $(TESTS_OBJS) $(NAME)
	$(CC) $(CFLAGS) -I$(INCLUDES) -Itests/includes $(TESTS_OBJS) $(NAME) $(LIBUNIT) -o $@

test: $(TEST_BIN)
	@./$(TEST_BIN)

%.o: %.c 
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

tests/%.o: tests/%.c 
	$(CC) $(CFLAGS) -I$(INCLUDES) -Itests/$(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TESTS_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re test
