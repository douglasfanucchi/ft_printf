#include "minunit.h"
#include "./structures/s_char_format.c"

int	main()
{
	MU_RUN_SUITE(tests_s_char_format);
	MU_REPORT();

	return (0);
}
