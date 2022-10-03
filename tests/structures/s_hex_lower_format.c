#include "../minunit.h"
#include <ft_printf.h>

MU_TEST(test_formatter) {
	t_data_format	*data_format = get_hex_lower_format();
	unsigned long	n;

	mu_check(data_format != NULL);

	n = -1;
	mu_check(!ft_strncmp(data_format->formatter(&n), "ffffffffffffffff", 16));

	n = 10;
	mu_check(!ft_strncmp(data_format->formatter(&n), "a", 1));

	n = 16;
	mu_check(!ft_strncmp(data_format->formatter(&n), "10", 1));

	free(data_format);
}

MU_TEST_SUITE(test_hex_lower_format) {
	MU_RUN_TEST(test_formatter);
}
