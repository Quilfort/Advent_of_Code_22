#include <aoc.h>
#include <stdio.h>

int find_string(char *string1, char *string2, char *string3)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	char answer;
	int ascii;
	int round;


	while (string1[x] != '\0')
	{
		y = 0;
		while (string2[y] != '\0')
		{
			if (string1[x] == string2[y])
			{
				z = 0;
				while (string3[z] != '\0')
				{
					if (string1[x] == string3[z])
					{
						answer = string1[x];
						break;
					}
					z++;
				}
			}
			y++;
		}
		x++;
	}
	printf("Letter = %c | ", answer);
	printf("ASCII = %d | ", answer);

	ascii = answer;
	if (upper_lower(answer) == 0)
	{
		//UPPERCASE
		round = ascii - 38;
	}
	else if (upper_lower(answer) == 1)
	{
		//LOWERCASE
		round = ascii - 96;
	}
	printf("Round = %d | \n", round);
	return (round);
}		

bool	execute_p2(t_data *data)
{
	printf(GREEN BOLD"Executing part 2\n"RESET);

	int i = 0;
	int counter = 1;
	int group = 1;
	int	len = 0;
	int total = 0;
	int line = 0;

	//char 	*string = ft_strdup("");

	char	*string1 = ft_strdup("");
	char	*string2 = ft_strdup("");
	char	*string3 = ft_strdup(""); 

	while (data->input[i] != '\0')
	{
	
		if (data->input[i] != '\n')
		{
			if (counter == 1)
				string1 = ft_strjoin(string1, data->input[i]);
			else if (counter == 2)
				string2 = ft_strjoin(string2, data->input[i]);
			else if (counter == 3)
				string3 = ft_strjoin(string3, data->input[i]);
		}
		else if (data->input[i] == '\n')
		{
			counter++;
		}
		if (counter == 4)
		{
			printf("Group %d: ", group);
			line = find_string(string1, string2, string3);
			total = total + line;
			line = 0;
			string1 = ft_strdup("");
			string2 = ft_strdup("");
			string3 = ft_strdup("");
			group++;
			counter = 1;
		}
		i++;
	}
	printf("Total = %d \n", total);
	
	if (data)
		return (true);
	return (false);
}
