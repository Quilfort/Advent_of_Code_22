#ifndef AOC_H
# define AOC_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

//========== Colors ============//
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"
# define LINE		"\x1b[4m"
# define BLINK		"\x1b[5m"
# define CROSS		"\x1b[9m"

typedef struct s_data
{
     char    *input;
}	t_data;

//===== Functions =====//

int	     main(int argc, char const *argv[]);
bool	     read_data(char **input);
bool	     parse_data(t_data *data_set, char **input);

bool	     execute_test(t_data *data);
bool	     execute_p1(t_data *data);
bool	     execute_p2(t_data *data);

     //utils
size_t    ft_strlen(const char *s);
char	     *ft_strncat(char *dest, const char *src, unsigned int n);
char	     *ft_strdup(const char *s1);
char      *ft_substr(char const *s, unsigned int start, size_t len);
int       ft_atoi(const char *str);
int       upper_lower(char ch);
char      *ft_strjoin(char const *s1, char const s2);
int       find_string(char *string1, char *string2, char *string3);

#endif