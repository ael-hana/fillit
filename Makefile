NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = check.c check2.c fillit.c list.c sort.c sort2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/ fclean
		make -C libft/
		$(CC) $(OBJ) $(FLAGS) -L libft/ -lft -o $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) -I libft/

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(OBJ) $(NAME)
	@make -C libft/ fclean

re: fclean all
