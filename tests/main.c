#include "minunit.h"
#include "./structures/s_char_format.c"
#include "./structures/s_str_format.c"
#include "./test_hex_base_converter.c"

int	main()
{
	MU_RUN_SUITE(tests_s_char_format);
	MU_RUN_SUITE(test_s_str_format);
	MU_RUN_SUITE(test_hex_base_converter);
	MU_REPORT();

	return (0);
}
