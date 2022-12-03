#include <aoc.h>
#include <stdio.h>

static int who_won_cheat(char elf, char myself)
{
	int count;
	int win = 6;
	int draw = 3;
	int lose = 0;
	int	rock = 1;
	int paper = 2;
	int scissor = 3;

	count = 0;

	if (myself == 'X')
	{
		count = lose;
		if (elf == 'A')
			count = count + scissor;
		else if (elf == 'B')
			count = count + rock;
		else if (elf == 'C')
			count = count + paper;
	}
	else if (myself == 'Y')
	{
		count = draw;
		if (elf == 'A')
			count = count + rock;
		else if (elf == 'B')
			count = count + paper;
		else if (elf == 'C')
			count = count + scissor;
	}
	else if (myself == 'Z')
	{
		count = win;
		if (elf == 'A')
			count = count + paper;
		else if (elf == 'B')
			count = count + scissor;
		else if (elf == 'C')
			count = count + rock;		
	}
	return (count);
}

bool	execute_p2(t_data *data)
{
	printf(GREEN BOLD"Executing part 2\n"RESET);

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
		round = who_won_cheat(elf, myself);
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
