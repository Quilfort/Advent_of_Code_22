#include <aoc.h>
#include <stdio.h>

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	upper_lower(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
    {
        return (0);
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        return (1);
    }
	return (2);
}

bool	execute_test(t_data *data)
{
	printf(GREEN BOLD"Executing test case\n"RESET);

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
