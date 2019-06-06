NAME		= libftprintf.a

SRC			= ft_printf.c aux_func.c conversion.c di_decimal.c
MAIN		= main.c
TEST_SRC	= test_parse.c

OBJ			= $(SRC:.c=.o)
MAIN_OBJ	= $(MAIN:.c=.o)
TEST_OBJ	= $(TEST_SRC:.c=.o)

AR			= ar
CC			= gcc
INC			= -I. -I libft/includes
LIB			= -Llibft/ -lft
FLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(AR) rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $(INC) -c $(SRC)

test: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) -c $(MAIN)
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) -L. -lftprintf -o printf $(MAIN_OBJ)

test_parse:
	make -C libft/
	$(CC) $(FLAGS) $(INC) -c $(SRC) $(TEST_SRC)
	$(CC) $(FLAGS) $(INC) $(LIB) -o test_parse $(OBJ) $(TEST_OBJ)

debug: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) -L. -lftprintf $(MAIN)

clean:
	rm -f $(OBJ) $(MAIN_OBJ)

clean_parse:
	rm -f test_parse
	rm -f $(TEST_OBJ)

clean_debug:
	rm -f a.out
	rm -rf a.out.dSYM 

fclean: clean clean_debug clean_parse
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

