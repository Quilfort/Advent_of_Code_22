#include <aoc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int	main(int argc, char const *argv[])
{
	char	*input;
	t_data	data_set;

	if (argc != 2 || atoi(argv[1]) > 2)
		return (printf(RED BOLD"Wrong input\n"RESET), EXIT_FAILURE);

	if (!read_data(&input))
		return (EXIT_FAILURE);
	if (!parse_data(&data_set, &input))
		return (EXIT_FAILURE);

	if (argv[1][0] == '0')
		if (!execute_test(&data_set))
			return (EXIT_FAILURE);
	if (argv[1][0] == '1')
		if (!execute_p1(&data_set))
			return (EXIT_FAILURE);
	if (argv[1][0] == '2')
		if (!execute_p2(&data_set))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
