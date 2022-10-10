NAME=libftprintf.a
TESTS=test.out
CC=cc
CC_FLAGS=-g3
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

BONUS_SOURCES = sources/flags/get_sharp_flag.c \
				sources/flags/get_space_flag.c \
				sources/flags/get_plus_flag.c \

BONUS_OBJECTS := $(BONUS_SOURCES:sources/flags/%=%)
BONUS_OBJECTS := $(BONUS_OBJECTS:.c=.o)

OBJECTS = $(SOURCES:.c=.o) $(SOURCES_FORMATS:.c=.o)
TESTS_SOURCES = tests/main.c \
				tests/test_find_format_from_str_start.c \
			    tests/test_hex_base_converter.c \
			    tests/test_ft_printf.c \
				tests/formats/s_char_format.c \
				tests/formats/s_decimal_format.c \
				tests/formats/s_hex_lower_format.c \
				tests/formats/s_hex_upper_format.c \
				tests/formats/s_integer_format.c \
				tests/formats/s_percentage_format.c \
				tests/formats/s_pointer_format.c \
				tests/formats/s_str_format.c \
				tests/formats/s_u_decimal_format.c \
				tests/flags/test_sharp_flag.c \
				tests/flags/test_space_flag.c \
				tests/flags/test_plus_flag.c \

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

$(BONUS_OBJECTS): $(BONUS_SOURCES)
	@$(CC) $(INCLUDES) -c $(BONUS_SOURCES)
clean:
	rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

tests: $(TESTS)
	@./$(TESTS)

$(TESTS): clean_tests $(LIBFT) $(OBJECTS) $(BONUS_OBJECTS) $(TESTS_SOURCES)
	@cc -g3 $(INCLUDES) $(OBJECTS) $(BONUS_OBJECTS) $(TESTS_SOURCES) $(LIBFT) -o $(TESTS)

clean_tests:
	@rm -f $(OBJECTS)
	@rm -f $(TESTS)
