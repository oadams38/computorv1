NAME = computor

SRCS = computor.c \
		computation.c \
		verifications.c \
		tools.c
		

OBJS = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) libft.a

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re