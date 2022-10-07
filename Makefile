NAME=libftprintf.a
TESTS=test.out
INCLUDES= -I ./includes -I libft
LIBFT=./libft/libft.a
OBJECTS= get_char_format.o \
		 get_decimal_format.o \
		 get_hex_lower_format.o \
		 get_hex_upper_format.o \
		 get_integer_format.o \
		 get_percentage_format.o \
		 get_pointer_format.o \
		 get_str_format.o \
		 get_u_decimal_format.o \
		 ft_printf.o \
		 hex_base_converter.o \
		 formats_list.o \

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJECTS)

$(LIBFT):
	rm -rf libft
	curl -LO https://github.com/douglasfanucchi/libft/archive/refs/heads/master.zip
	unzip master.zip
	rm master.zip
	mv -f libft-master libft
	cd libft
	make -C libft/
	make bonus -C libft/

$(OBJECTS):
	cc $(INCLUDES) -Wall -Wextra -Werror -c sources/*.c sources/**/*.c

clean:
	rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

tests: $(TESTS)
	@./$(TESTS)

$(TESTS): clean_tests $(LIBFT)	@cc -g3 $(FLAGS) $(INCLUDES) sources/*.c sources/**/*.c tests/*.c tests/**/*.c $(LIBFT) -o $(TESTS)

clean_tests:
	@rm -f $(TESTS)
