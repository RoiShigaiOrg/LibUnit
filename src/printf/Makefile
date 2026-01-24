CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rsc
RM = rm -f

NAME = libftprintf.a

HEADER=includes/

SRCS = 	src/ft_printf.c \
		src/args.c \
		src/flags2.c \
		src/convert_base.c \
		src/unsigned_convert_base.c \
		src/ft_strlen.c \
		src/ft_strjoin.c \
		src/ft_strdup.c \
		src/ft_calloc.c \
		src/ft_memset.c \
		src/ft_memcpy.c \
		src/ft_strlcat.c

OBJS = $(SRCS:.c=.o)


all: $(OBJS)
	 $(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)  

fclean: clean
	$(RM) $(NAME)
 
re: fclean all

.PHONY: all clean fclean re
