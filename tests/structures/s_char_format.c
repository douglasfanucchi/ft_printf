#include "../minunit.h"
#include <ft_printf.h>

MU_TEST(test_get_char_format) {
	t_data_format	*data_format;
	
	data_format = get_char_format();
	mu_check(data_format != NULL);
	mu_check(!ft_strncmp(data_format->id, "%c", 2));
	
	free(data_format);
}

MU_TEST(test_char_formatter) {
	t_data_format	*data_format;

	data_format = get_char_format();
	char *str = "testing";
	
	mu_check(!ft_strncmp(data_format->formatter(str), "t", 1));

	free(data_format);
}

MU_TEST_SUITE(tests_s_char_format) {
	MU_RUN_TEST(test_get_char_format);
	MU_RUN_TEST(test_char_formatter);
}
