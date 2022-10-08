NAME=libftprintf.a
TESTS=test.out
CC=cc
CC_FLAGS=-Wall -Wextra -Werror
INCLUDES= -I ./includes -I libft
LIBFT=./libft/libft.a
SOURCES_FORMATS = get_char_format.c \
		get_decimal_format.c \
		get_hex_lower_format.c \
		get_hex_upper_format.c \
		get_integer_format.c \
		get_percentage_format.c \
		get_pointer_format.c \
		get_str_format.c \
		get_u_decimal_format.c \

SOURCES = ft_printf.c \
		hex_base_converter.c \
		formats_list.c \

OBJECTS = $(SOURCES:.c=.o) $(SOURCES_FORMATS:.c=.o)
TESTS_SOURCES = tests/main.c \
				tests/test_find_format_from_str_start.c \
			    tests/test_hex_base_converter.c \
				tests/structures/s_char_format.c \
				tests/structures/s_decimal_format.c \
				tests/structures/s_hex_lower_format.c \
				tests/structures/s_hex_upper_format.c \
				tests/structures/s_integer_format.c \
				tests/structures/s_percentage_format.c \
				tests/structures/s_pointer_format.c \
				tests/structures/s_str_format.c \
				tests/structures/s_u_decimal_format.c \

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
	make -C libft/
	make bonus -C libft/

$(OBJECTS): $(addprefix sources/, $(SOURCES)) $(addprefix sources/formats/, $(SOURCES_FORMATS))
	@$(CC) $(INCLUDES) $(CC_FLAGS) -c $(addprefix sources/, $(SOURCES)) $(addprefix sources/formats/, $(SOURCES_FORMATS))

clean:
	rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

tests: $(TESTS)
	@./$(TESTS)

$(TESTS): clean_tests $(LIBFT) $(OBJECTS) $(TESTS_SOURCES)
	@cc -g3 $(CC_FLAGS) $(INCLUDES) $(OBJECTS) $(TESTS_SOURCES) $(LIBFT) -o $(TESTS)

clean_tests:
	@rm -f $(OBJECTS)
	@rm -f $(TESTS)
