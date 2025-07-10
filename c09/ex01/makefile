# Variables
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I includes
SRCS_DIR	= srcs
OBJS_DIR	= objs

# Source files
SRCS		= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS		= $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
