#include "../minunit.h"
#include <ft_printf.h>

static char	*function_to_test_str_get_arg(t_data_format *data_format, ...)
{
	va_list	ap;
	char	*result = malloc(sizeof(char *));
	char	*arg;

	va_start(ap, data_format);
	arg = data_format->get_arg(ap);
	ft_strlcpy(result, arg, ft_strlen(arg) + 1);
	va_end(ap);
	return (result);
}

MU_TEST(test_str_formatter) {
	t_data_format	*data_format;

	data_format = get_str_format();

	mu_check(data_format != NULL);
	mu_check(!ft_strncmp(data_format->formatter("test"), "test", 4));
	mu_check(data_format->formatter("\0"));
	mu_check(*(data_format->formatter("\0")) == 0);

	free(data_format);
}

MU_TEST(test_str_get_arg) {
	t_data_format	*data_format;
	char			*result;

	data_format = get_str_format();
	mu_check(data_format != NULL);

	result = function_to_test_str_get_arg(data_format, "test");
	mu_check(!ft_strncmp(result, "test", 4));
	free(result);

	result = function_to_test_str_get_arg(data_format, "\0");
	mu_check(*result == 0);
	free(result);

	result = function_to_test_str_get_arg(data_format, "douglas\0fanucchi");
	mu_check(!ft_strncmp(result, "douglas", ft_strlen(result)));
	mu_check(ft_memcmp(result, "douglas\0fanucchi", 16) < 0);
	free(result);

	free(data_format);
}

MU_TEST_SUITE(test_s_str_format) {
	MU_RUN_TEST(test_str_formatter);
	MU_RUN_TEST(test_str_get_arg);
}
