#include <ft_printf.h>
#include "minunit.h"

MU_TEST(test_simple_convertion) {
	t_hex_base_converter	*converter;

	converter = get_hex_base_converter();
	mu_check(converter != NULL);

	mu_check(!ft_strncmp(converter->convert(16), "F", 1));

	free(converter);
}

MU_TEST_SUITE(test_hex_base_converter) {
	MU_RUN_TEST(test_simple_convertion);
}
