NAME		= libftprint.a

SRC			= ft_printf.c aux_func.c
TEST_SRC	= test_parse.c

OBJ			= $(SRC:.c=.o)
TEST_OBJ	= $(TEST_SRC:.c=.o)

CC			= gcc
INC			= -I. -I libft/includes
LIB			= -Llibft/ -lft
FLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME) $(OBJ) $(MAIN_OBJ)

$(OBJ): $(SRC) $(TEST_SRC)
	$(CC) $(FLAGS) $(INC) -c $(SRC) $(MAIN)

test_parse:
	make -C libft/
	$(CC) $(FLAGS) $(INC) -c $(SRC) $(TEST_SRC)
	$(CC) $(FLAGS) $(INC) $(LIB) -o test_parse $(OBJ) $(TEST_OBJ)

debug:
	make -C libft/
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) $(SRC) $(TEST_SRC)

clean:
	rm -f $(OBJ) $(MAIN_OBJ)

clean_parse:
	rm -f test_parse
	rm -f $(TEST_OBJ)

clean_debug:
	rm -f a.out
	rm -rf a.out.dSYM 

fclean: clean clean_debug clean_parse
	rm -f $(NAME)

re: fclean all

