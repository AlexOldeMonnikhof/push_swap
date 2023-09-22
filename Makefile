NAME = push_swap
OBJ_DIR = obj
CC = gcc
HEADER = push_swap.h
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c libft_utils.c hardcode.c swap.c radixsort.c push.c lst_functions.c free.c
VPATH = src/
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@printf "push_swap compiled\n"

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	@$(CC) -g $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re