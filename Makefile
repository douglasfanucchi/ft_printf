NAME=libftprintf.a
TESTS=test.out
INCLUDES= -I ./includes -I libft
LIBFT=./libft/libft.a

tests: $(TESTS)
	@./$(TESTS)

$(TESTS): clean_tests
	@cc -g3 $(FLAGS) $(INCLUDES) sources/*.c sources/**/*.c tests/*.c tests/**/*.c $(LIBFT) -o $(TESTS)

clean_tests:
	@rm -f $(TESTS)
