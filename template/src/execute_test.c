#include <aoc.h>
#include <stdio.h>

bool	execute_test(t_data *data)
{
	printf(GREEN BOLD"Executing test case\n"RESET);
	if (data)
		return (true);
	return (false);
}
