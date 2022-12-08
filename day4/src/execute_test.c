#include <aoc.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*pointer;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = 1;
	pointer = malloc(s1len + s2len + 1);
	if (pointer == NULL)
		return (pointer);
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[s1len] = s2;
	pointer[s1len + s2len] = '\0';
	return (pointer);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*dst;

	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	if (start > slen || len > slen)
		return (ft_strdup(""));
	dst = malloc(len + 1);
	if (dst == NULL)
		return (dst);
	dst[len] = '\0';
	while (len > 0)
	{
		len--;
		dst[len] = s[start + len];
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char		*destination;
	char		*pointer;
	size_t		len;

	len = 0;
	while (s1[len])
		len++;
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

static bool check_pairs(char *string1, char *string2, char *string3, char *string4)
{
	int firstl = ft_atoi(string1);
	int firstr = ft_atoi(string2);
	int secondl = ft_atoi(string3);
	int secondr = ft_atoi(string4);


	printf("%d - ", firstl);
	printf("%d | ", firstr);
	printf("%d - ", secondl);
	printf("%d | ", secondr);

	int diff1;
	int diff2;

	diff1 = firstl - firstr;
	diff2 = secondl - secondr;


	// 3 - 5  3 - 6
	//  2  en 3
	// 3 < 6
	// 3 >= 3
	// 3 + 2 < 6

	if (diff1 < diff2)
	{
		if (firstl < secondr)
		{
			if (firstl >= secondl)
			{
				if ((secondl + diff1) < secondr)
					return (true);
			}
		}
	}
	else if (diff2 < diff1)
	{
		if (secondl < firstr)
		{
			if (secondl >= firstl)
			{
				if ((firstl + diff1) < firstr)
					return (true);
			}
		}
	}

	return (false);







}

bool	execute_test(t_data *data)
{
	printf(GREEN BOLD"Executing test case\n"RESET);

	int i = 0;
	int total = 0;
	int	number = 1;

	char	*string1 = ft_strdup("");
	char	*string2 = ft_strdup("");
	char	*string3 = ft_strdup(""); 
	char	*string4 = ft_strdup("");

	while (data->input[i] != '\0')
	{
		while(data->input[i] != '-')
		{
			string1 = ft_strjoin(string1, data->input[i]);
			i++;
		}
		i++;
		while(data->input[i] != ',')
		{
			string2 = ft_strjoin(string2, data->input[i]);
			i++;
		}
		i++;
		while(data->input[i] != '-')
		{
			string3 = ft_strjoin(string3, data->input[i]);
			i++;
		}
		i++;
		while(data->input[i] != '\n')
		{
			string4 = ft_strjoin(string4, data->input[i]);
			i++;
		}

		if (data->input[i] == '\n')
		{
			printf("%d | ", number);
			if (check_pairs(string1, string2, string3, string4) == true)
			{
				total++;
				printf("DONT CLEAN\n");
			}
			else
				printf("Should be cleaned\n");
			string1 = ft_strdup("");
			string2 = ft_strdup("");
			string3 = ft_strdup("");
			string4	= ft_strdup("");
			i++;
			number++;
		}
	} 


	printf("Dit is totaal = %d\n", total);

	if (data)
		return (true);
	return (false);
}
