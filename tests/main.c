#include "minunit.h"
#include "./structures/s_char_format.c"
#include "./structures/s_str_format.c"
#include "./structures/s_hex_lower_format.c"
#include "./structures/s_hex_upper_format.c"
#include "./structures/s_pointer_format.c"
#include "./structures/s_decimal_format.c"
#include "./structures/s_integer_format.c"
#include "./structures/s_u_decimal_format.c"
#include "./test_hex_base_converter.c"

int	main()
{
	MU_RUN_SUITE(tests_s_char_format);
	MU_RUN_SUITE(test_s_str_format);
	MU_RUN_SUITE(test_hex_base_converter);
	MU_RUN_SUITE(test_hex_lower_format);
	MU_RUN_SUITE(test_hex_upper_format);
	MU_RUN_SUITE(test_pointer_format);
	MU_RUN_SUITE(test_decimal_format);
	MU_RUN_SUITE(test_integer_format);
	MU_RUN_SUITE(test_u_decimal_format);
	MU_REPORT();

	return (0);
}
