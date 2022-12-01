#include <aoc.h>
#include <stdio.h>

bool	execute_p2(t_data *data)
{
	printf(GREEN BOLD"Executing part 2\n"RESET);

		int i;
	int elves;

	i = 0;
	elves = 1;

	char *string;
	int	total;
	int temp;

	total = 0;
	temp = 0;

	int k = 0;

	int win_elf_1 = 0;
	int win_cal_1 = 0;

	int win_elf_2 = 0;
	int win_cal_2 = 0;

	int win_elf_3 = 0;
	int win_cal_3 = 0;

	//int temp_win_elf_1 = 0;
	//int temp_win_cal_1 = 0;

	//int temp_win_elf_2 = 0;
	//int temp_win_cal_2 = 0;

	int win_cal_total = 0;

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

				if (k == 0)
					win_cal_1 = total;
				if (k == 1)
					win_cal_2 = total;
				if (k == 2)
					win_cal_3 = total;	
				if (k > 2)
				{
					if (win_cal_1 < total)
					{
						
						if (win_cal_1 > win_cal_2)
						{
							win_cal_2 = win_cal_1;
							win_elf_2 = win_cal_1;

							if (win_cal_2 > win_cal_3)
							{
								win_cal_3 = win_cal_2;
								win_elf_3 = win_cal_2;
							}
						}
						else if (win_cal_1 > win_cal_3)
						{
							win_cal_3 = win_cal_1;
							win_elf_3 = win_cal_1;
						}

						win_cal_1 = total;
						win_elf_1 = elves;

					}
					else if (win_cal_2 < total)
					{
						if (win_cal_2 > win_cal_3)
						{
							win_cal_3 = win_cal_2;
							win_elf_3 = win_cal_2;
						}
						
						win_cal_2 = total;
						win_elf_2 = elves;
					}
					else if (win_cal_3 < total)
					{
						win_cal_3 = total;
						win_elf_3 = elves;
					}
				}
				elves++;
				k++;
				total = 0;
			}
		}
		i++;
	}
	printf("\n\n");
	printf("Winner Elf number : %d | ", win_elf_1 + 1);
	printf("Winner Calories: %d\n", win_cal_1);
	printf("\n");
	printf("Winner Elf number : %d | ", win_elf_2 + 1);
	printf("Winner Calories: %d\n", win_cal_2);
	printf("\n");
	printf("Winner Elf number : %d | ", win_elf_3 + 1);
	printf("Winner Calories: %d\n", win_cal_3);
	printf("\n");
	printf("Total Calories: %d\n", (win_cal_1 + win_cal_2 + win_cal_3));

	if (data)
		return (true);
	return (false);
}
