CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c utils1.c utils2.c utils3.c utils4.c utils5.c \
		  stack_work.c swap.c rotate.c revrotate.c sort1.c sort2.c sort3.c \
		  parse_args.c ft_printf.c ft_printhex.c ft_printptr.c push.c \
		
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