#include "../minunit.h"
#include <ft_printf.h>

MU_TEST(test_percentage_id) {
	t_data_format	*data_format = get_percentage_format();
	
	mu_check(data_format != NULL);
	mu_check(!ft_strncmp(data_format->id, "%%", 2));

	free(data_format);
}

MU_TEST(test_percentage_formatter) {
	t_data_format	*data_format = get_percentage_format();

	mu_check(data_format != NULL);

	char	*s = "%%";
	char	*result;

	result = data_format->formatter(s);
	mu_check(!ft_strncmp(result, "%", 1));
	free(result);

	free(data_format);
}

static void	testing_percentage_get_arg(t_data_format *data_format, ...)
{
	va_list	ap;

	va_start(ap, data_format);

	char *result = data_format->get_arg(ap);
	mu_check(!ft_strncmp(result, "%%", 2));
	mu_check(!ft_strncmp(va_arg(ap, char *), "testing", 7));
	free(result);

	va_end(ap);
}

MU_TEST(test_percentage_get_arg) {
	t_data_format	*data_format = get_percentage_format();

	mu_check(data_format != NULL);
	testing_percentage_get_arg(data_format, "testing");

	free(data_format);
}

MU_TEST_SUITE(test_percentage_format) {
	MU_RUN_TEST(test_percentage_id);
	MU_RUN_TEST(test_percentage_formatter);
	MU_RUN_TEST(test_percentage_get_arg);
}
