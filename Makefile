NAME		= libftprintf.a

SRC			= ft_printf aux_func conversion \
			  conversions/char \
			  conversions/color \
			  conversions/integer \
			  conversions/mod \
			  conversions/string \
			  conversions/unsigned_integer \
			  conversions/get_con \
			  conversions/get_unsigned_con
MAIN		= test/main.c

SRC_DIR		= src
OBJ_DIR		= obj

OBJS		= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

MAIN_OBJ	= $(MAIN:.c=.o)

AR			= ar
CC			= gcc
LIB			= -Llib -lft
INC_FLAGS	= -I inc -I lib/inc
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@make -C lib/
	@ar -x lib/libft.a && mv *.o $(OBJ_DIR)
	@$(AR) -rcs $@ $(OBJS) $(OBJ_DIR)/*.o
	@ranlib $(NAME)
	@rm "__.SYMDEF SORTED"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

test: 
	$(CC) $(FLAGS) $(INC_FLAGS) -c $(MAIN)
	$(CC) $(FLAGS) $(INC_FLAGS) -L. -lftprintf -o printf $(MAIN_OBJ)

debug2: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) lib/*.c test_vector.c
debug: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) src/*.c src/conversions/*.c lib/*.c $(MAIN)

clean: clean_debug
	make clean -C lib/
	rm -rf $(OBJ_DIR)
	rm -f $(MAIN_OBJ)	

clean_debug:
	rm -f a.out
	rm -rf a.out.dSYM 

fclean: clean clean_debug
	make fclean -C lib/
	rm -f $(NAME)

re: fclean all

