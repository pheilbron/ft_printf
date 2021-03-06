# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 19:31:10 by pheilbro          #+#    #+#              #
#    Updated: 2019/08/29 19:05:31 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC			= ft_printf ft_sprintf parse_data format printf_adjust_fw \
			  printf_type convert_data ft_fstring ft_printf_ldtoa \
			  conversions/char \
			  conversions/chars_written \
			  conversions/color \
			  conversions/float \
			  conversions/integer \
			  conversions/mod \
			  conversions/non_print_string \
			  conversions/pointer \
			  conversions/string \
			  conversions/unsigned_integer
MAIN		= main.c

SRC_DIR		= src
OBJ_DIR		= obj

OBJS		= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

MAIN_OBJ	= main.o

AR			= ar
CC			= gcc
LIB			= -Llib -lft
INC_FLAGS	= -I inc -I lib/inc
CFLAGS		= -Wall -Werror -Wextra 
DEBUG_FLAGS	= -fsanitize=address -g 

all: $(NAME)

$(NAME): $(OBJS)
	@make -C lib/
	@ar -x lib/libft.a && mv *.o $(OBJ_DIR)
	@$(AR) -rcs $@ $(OBJS) $(OBJ_DIR)/*.o
	@ranlib $(NAME)
	@rm -f "__.SYMDEF SORTED"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

test_printf: 
	$(CC) $(FLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) -c $(MAIN)
	$(CC) $(FLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) -L. -lftprintf -o printf $(MAIN_OBJ)

debug: all
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) src/*.c src/conversions/*.c lib/src/*/*.c $(MAIN)

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
