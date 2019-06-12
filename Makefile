NAME		= libftprintf.a

SRC			= ft_printf.c aux_func.c conversion.c set_format_string.c
MAIN		= main.c
TEST_SRC	= test_parse.c

OBJ			= $(SRC:.c=.o)
MAIN_OBJ	= $(MAIN:.c=.o)
TEST_OBJ	= $(TEST_SRC:.c=.o)

AR			= ar
CC			= gcc
INC			= -I. -I libft/includes
FLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	ar -x libft/libft.a && mv *.o obj/
	$(CC) $(FLAGS) $(INC) -c $(SRC)
	$(AR) -rcs $@ $(OBJ) obj/*.o
	ranlib $(NAME)
	rm "__.SYMDEF SORTED"

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $(INC) -c $(SRC)

test: 
	make -C libft/
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) -c $(MAIN) $(SRC)
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) -o printf $(MAIN_OBJ) $(OBJ)

test_parse:
	make -C libft/
	$(CC) $(FLAGS) $(INC) -c $(SRC) $(TEST_SRC)
	$(CC) $(FLAGS) $(INC) $(LIB) -o test_parse $(OBJ) $(TEST_OBJ)

debug: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) -L. -lftprintf $(MAIN)

clean: clean_parse clean_debug
	make clean -C libft/
	rm -f obj/*.c
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

