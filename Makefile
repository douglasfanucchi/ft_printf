NAME=libftprintf.a
TESTS=test.out
CC=cc
CC_FLAGS=-Wall -Werror -Wextra
INCLUDES= -I ./includes -I libft
LIBFT=./libft/libft.a

SOURCES = sources/ft_printf.c \
		sources/hex_base_converter.c \
		sources/formats_list.c \
		sources/formats/get_char_format.c \
		sources/formats/get_decimal_format.c \
		sources/formats/get_hex_lower_format.c \
		sources/formats/get_hex_upper_format.c \
		sources/formats/get_integer_format.c \
		sources/formats/get_percentage_format.c \
		sources/formats/get_pointer_format.c \
		sources/formats/get_str_format.c \
		sources/formats/get_u_decimal_format.c \

OBJECTS := $(SOURCES:.c=.o) $(SOURCES_FORMATS:.c=.o)
OBJECTS := $(OBJECTS:sources/%=%)
OBJECTS := $(OBJECTS:formats/%=%)

BONUS_SOURCES = sources/flags/get_sharp_flag.c \
				sources/flags/get_space_flag.c \
				sources/flags/get_plus_flag.c \
				sources/flags/apply_flags.c \

BONUS_OBJECTS := $(BONUS_SOURCES:sources/flags/%=%)
BONUS_OBJECTS := $(BONUS_OBJECTS:.c=.o)

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

$(OBJECTS): $(SOURCES)
	@$(CC) $(INCLUDES) $(CC_FLAGS) -c $(SOURCES)

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
