#include "../minunit.h"
#include <ft_printf.h>

static void	func_testing_get_arg_hex_lower(t_data_format *data_format, ...)
{
	va_list ap;

	va_start(ap, data_format);
	int	*nb = data_format->get_arg(ap);
	mu_check(*nb == 123);
	va_end(ap);
}

MU_TEST(testing_get_arg_hex_lower) {
	t_data_format	*data_format = get_hex_lower_format();
	func_testing_get_arg_hex_lower(data_format, 123);
	free(data_format);
}

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
	MU_RUN_TEST(testing_get_arg_hex_lower);
}
