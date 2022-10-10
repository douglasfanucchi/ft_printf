#include "../minunit.h"
#include <ft_printf.h>

MU_TEST(test_get_sharp_flag) {
	t_flag	*flag = get_sharp_flag();

	mu_check(flag != NULL);
	mu_check(!ft_strncmp(flag->type, "#", 1));
	mu_check(flag->formatter != NULL);
	
	free(flag);
}

MU_TEST(test_sharp_formatter) {
	t_flag	*flag = get_sharp_flag();
	char	*result;

	mu_check(flag != NULL);

	result = flag->formatter("0");
	mu_check(!ft_strncmp(result, "0", 1));
	free(result);

	result = flag->formatter("f");
	mu_check(!ft_strncmp(result, "0xf", 3));
	free(result);

	free(flag);
}

MU_TEST_SUITE(test_sharp_flag) {
	MU_RUN_TEST(test_get_sharp_flag);
	MU_RUN_TEST(test_sharp_formatter);
}
