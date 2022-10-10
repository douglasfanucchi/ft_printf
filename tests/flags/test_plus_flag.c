#include "../minunit.h"
#include <ft_printf.h>

MU_TEST(test_get_plus_flag) {
	t_flag	*flag = get_plus_flag();

	mu_check(flag != NULL);
	mu_check(!ft_strncmp(flag->type, "+", 1));

	free(flag);
}

MU_TEST(test_plus_flag_formatter) {
	t_flag	*flag = get_plus_flag();
	char	*result;

	mu_check(flag != NULL);

	result = flag->formatter("0");
	mu_check(!ft_strncmp(result, "+0", 2));
	free(result);

	result = flag->formatter(" 0");
	mu_check(!ft_strncmp(result, "+0", 2));
	free(result);

	result = flag->formatter("-1");
	mu_check(!ft_strncmp(result, "-1", 2));
	free(result);

	free(flag);
}

MU_TEST_SUITE(test_plus_flag) {
	MU_RUN_TEST(test_get_plus_flag);
	MU_RUN_TEST(test_plus_flag_formatter);
}
