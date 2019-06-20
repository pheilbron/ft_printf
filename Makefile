NAME		= libftprintf.a

FILES		= ft_printf.c aux_func.c conversion.c \
			  conversions/char.c \
			  conversions/color.c \
			  conversions/integer.c \
			  conversions/mod.c \
			  conversions/string.c \
			  conversions/unsigned_integer.c \
			  conversions/get_con.c \
			  conversions/get_unsigned_con.c
MAIN		= main.c

SRC_DIR		= ./src
OBJ_DIR	=./obj

SRCS		= $(addprefix $(SRC_DIR),$(FILES))

OBJS		= $(sort $(wildcard $(OBJ_DIR)/*.o))
MAIN_OBJ	= $(MAIN:.c=.o)

AR			= ar
CC			= gcc
LIB			= -Llibft -lft
INC_FLAGS	= -I inc -I lib/includes
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

all: $(OBJ_DIR)/$(NAME)

$(OBJ_DIR)/$(NAME): $(OBJS)
	@make -C lib/
	ar -x lib/libft.a
	$(AR) -rcs $@ $< 
	ranlib $(NAME)
	rm "__.SYMDEF SORTED"
	mv $(NAME) .

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

test: 
	$(CC) $(FLAGS) $(INC) -c $(MAIN) $(SRC)
	$(CC) $(FLAGS) $(INC) -L. -lftprintf -o printf $(MAIN_OBJ) $(OBJ)

debug: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) -L. -lftprintf $(MAIN)

clean: clean_debug
	make clean -C lib/
	rm -f obj/*.c
	rm -f $(OBJ) $(MAIN_OBJ)

clean_debug:
	rm -f a.out
	rm -rf a.out.dSYM 

fclean: clean clean_debug
	make fclean -C lib/
	rm -f $(NAME)

re: fclean all

