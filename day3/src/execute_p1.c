#include <aoc.h>
#include <stdio.h>

static int find_character(char *string, int len, char *left, char *right)
{
	int i = 0;
	int half = len / 2;
	int x = 0;
	int y = 0;
	char answer;
	int ascii;
	int round;


	left = ft_substr(string, i, half);
	right = ft_substr(string, half, half);

	while (left[x] != '\0')
	{
		y = 0;
		while (right[y] != '\0')
		{
			if (left[x] == right[y])
			{
				answer = left[x];
				break;
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

bool	execute_p1(t_data *data)
{
	printf(GREEN BOLD"Executing part 1\n"RESET);

	int i = 0;
	int	k = 1;
	int	len = 0;
	int total = 0;
	int line = 0;

	char	*string = ft_strdup("");
	char	*left = ft_strdup("");
	char	*right = ft_strdup("");

	while (data->input[i] != '\0')
	{
		if(data->input[i] != '\n')
			ft_strncat(string, &data->input[i], 1);
		else if (data->input[i] == '\n')
		{
			len = ft_strlen(string);
			printf("Number %d: ", k);
			line = find_character(string, len, left, right);
			total = total + line;
			line = 0;
			string = ft_strdup("");
			left = ft_strdup("");
			right = ft_strdup("");
			k++;
		}
		i++;
	}
	printf("Total = %d \n", total);

	if (data)
		return (true);
	return (false);
}
