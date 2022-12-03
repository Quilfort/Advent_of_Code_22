#include <aoc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

bool	read_data(char **input)
{
	long	length;
	FILE	*fd = NULL;

	*input = 0;
	printf(GREEN BOLD"Reading input file\n"RESET);
	fd = fopen("files/input.txt", "rw+");
	if (!fd)
		printf("%s\n", strerror(errno));
	if (fd)
	{
		if (fseek (fd, 0, SEEK_END) == -1)
			return (false);
		length = ftell (fd);
		if (length < 0)
			return (false);
		if (fseek (fd, 0, SEEK_SET) == -1)
			return (false);
		*input = malloc (length);
		if (!*input)
			return (false);
		if (*input)
			fread (*input, 1, length, fd);
		fclose (fd);
		return (true);
	}
	return (false);
}