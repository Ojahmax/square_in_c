NAME = rush01

SRCS = main.c parse.c solve.c print.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)  # Default target

$(NAME): $(OBJS)  # Link object files
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c  # Compile each .c to .o
	$(CC) $(CFLAGS) -c $< -o $@

clean:  # Remove object files
	rm -f $(OBJS)

fclean: clean  # Remove executable too
	rm -f $(NAME)

re: fclean all  # Rebuild from scratch

.PHONY: all clean fclean re  # These aren't actual files
