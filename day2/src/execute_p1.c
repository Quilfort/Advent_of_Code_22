#include <aoc.h>
#include <stdio.h>

static int who_won(char elf, char myself)
{
	int count;

	count = 0;

	if (myself == 'X')
		count = 1;
	else if (myself == 'Y')
		count = 2;
	else if (myself == 'Z')
		count = 3;


	if (elf == 'A')
	{
		if (myself == 'X')
			count = count + 3;
		else if (myself == 'Y')
			count = count + 6;
		else if (myself == 'Z')
			count = count + 0;
	}
	else if (elf == 'B')
	{
		if (myself == 'X')
			count = count + 0;
		else if (myself == 'Y')
			count = count + 3;
		else if (myself == 'Z')
			count = count + 6;
	}
	else if (elf == 'C')
	{
		if (myself == 'X')
			count = count + 6;
		else if (myself == 'Y')
			count = count + 0;
		else if (myself == 'Z')
			count = count + 3;
	}
	return (count);
}

bool	execute_p1(t_data *data)
{
	printf(GREEN BOLD"Executing part 1\n"RESET);

	// A = Rock | B = Paper | C = Scissorts
	// X = Rock | Y = Paper | Z = Scissorrs
	// Rock = 1 | Paper = 2 | Scissors = 3
	// Lost = 0 | Draw = 3 | Win = 6

	int		total;
	int		round;
	int 	i;
	int 	x;
	char	elf;
	char	myself;

	i = 0 ;
	x = 1 ;
	total = 0;
	while (data->input[i] != '\0')
	{
		
		elf = data->input[i];
		i = i + 2;
		myself = data->input[i];
		round = who_won(elf, myself);
		printf("Match %d = %d\n", x, round);
		total = total + round;
		round = 0;
		i = i + 2;
		x++;
	}
	printf("This is total = %d\n", total);
	
	if (data)
		return (true);
	return (false);
}
