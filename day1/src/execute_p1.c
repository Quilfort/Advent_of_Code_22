#include <aoc.h>
#include <stdio.h>

bool	execute_p1(t_data *data)
{
	printf(GREEN BOLD"Executing part 1\n"RESET);
	int i;
	int elves;

	i = 0;
	elves = 1;

	char *string;
	int	total;
	int temp;

	total = 0;
	temp = 0;

	int win_elf = 0;
	int win_cal = 0;

	string = ft_strdup("");
	while (data->input[i] != '\0')
	{
		
		if(data->input[i] != '\n')
		{
			ft_strncat(string, &data->input[i], 1);
		}
		if (data->input[i] == '\n')
		{
			temp = ft_atoi(string);
			total = temp + total;
			string = ft_strdup("");;		
			if (data->input[i + 1] == '\n')
			{
				printf("Elf number: %d | ", elves);
				printf("Calories: %d\n", total);
				if (win_cal == 0)
					win_cal = total;
				if (win_cal < total)
				{
					win_cal = total;
					win_elf = elves;
				}
				elves++;
				total = 0;
			}
		}
		i++;
	}
	printf("\n\n");
	printf("Winner Elf number : %d | ", win_elf + 1);
	printf("Winner Calories: %d\n", win_cal);

	if (data)
		return (true);
	return (false);
}
