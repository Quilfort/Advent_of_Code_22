#include <aoc.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	negative;
	int	i;
	int	num;

	i = 0;
	negative = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * negative);
}

char	*ft_strncat(char *dest, const char *src, unsigned int n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char		*destination;
	char		*pointer;
	size_t		len;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	destination = malloc (len + 1);
	if (destination == NULL)
		return (destination);
	pointer = destination;
	while (*s1)
	{
		*pointer = *s1;
		pointer++;
		s1++;
	}
	*pointer = '\0';
	return (destination);
}

bool	execute_test(t_data *data)
{
	printf(GREEN BOLD"Executing test case\n"RESET);

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
