CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c utils.c swap.c stack.c split.c sort.c sort_three.c \
		  rotate.c rev_rotate.c push.c position.c check_input.c calc_cost.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re