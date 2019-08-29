# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 19:31:10 by pheilbro          #+#    #+#              #
#    Updated: 2019/08/28 20:20:49 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC			= ft_printf ft_sprintf parse_data format printf_adjust_fw \
			  printf_type convert_data ft_fstring ft_printf_ldtoa \
			  conversions/temp \
			  conversions/char \
			  conversions/chars_written \
			  conversions/color \
			  conversions/float \
			  conversions/integer \
			  conversions/mod \
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
LIB			= -l../libft -lft
INC_FLAGS	= -I inc -I ../libft/inc
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -fsanitize=address -g 

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ../libft/
	@ar -x ../libft/libft.a && mv *.o $(OBJ_DIR)
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
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) src/*.c src/conversions/*.c ../libft/src/*/*.c $(MAIN)
#	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) src/*.c src/conversions/*.c lib/ctype/*.c lib/stdlib/*.c lib/stdio/*.c lib/string/*.c lib/vector/*.c lib/dstring/*.c lib/math/*.c $(MAIN)

clean: clean_debug
	#make clean -C lib/
	rm -rf $(OBJ_DIR)
	rm -f $(MAIN_OBJ)

clean_debug:
	rm -f a.out
	rm -rf a.out.dSYM 

fclean: clean clean_debug
	#make fclean -C lib/
	rm -f $(NAME)

re: fclean all
