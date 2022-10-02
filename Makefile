NAME=libftprintf.a
TESTS=test.out
INCLUDES= -I ./includes -I libft
LIBFT=./libft/libft.a

tests: $(TESTS)
	@./$(TESTS)

$(TESTS): clean_tests
	@cc $(INCLUDES) sources/**/*.c tests/*.c tests/**/*.c $(LIBFT) -o $(TESTS)

clean_tests:
	@rm -f $(TESTS)
