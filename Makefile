NAME		= libftprintf.a

SRC			= ft_printf.c aux_func.c conversion.c set_format_string.c
MAIN		= main.c

OBJ			= $(SRC:.c=.o)
MAIN_OBJ	= $(MAIN:.c=.o)

AR			= ar
CC			= gcc
LIB			= -Llibft -lft
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
	$(CC) $(FLAGS) $(INC) -c $(MAIN) $(SRC)
	$(CC) $(FLAGS) $(INC) -L. -lftprintf -o printf $(MAIN_OBJ) $(OBJ)

debug: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) -L. -lftprintf $(MAIN)

clean: clean_debug
	make clean -C libft/
	rm -f obj/*.c
	rm -f $(OBJ) $(MAIN_OBJ)

clean_debug:
	rm -f a.out
	rm -rf a.out.dSYM 

fclean: clean clean_debug
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

