#include <stdio.h>
void	print_solution(char *str, int index, int open, int close, int remove, int min_remove, char *buffer)
{
	if (str[index] == '\0')
	{
		if (open == close && remove == min_remove)
		{
			buffer[index] = '\0';
			puts(buffer);
		}
		return ;
	}

	char c = str[index];
	if (c == '(' || c == ')')
	{
		buffer[index] = c;
		if (c == '(')
			print_solution(str, index + 1, open + 1, close, remove, min_remove, buffer);
		else if(open > close)
			print_solution(str, index + 1, open, close + 1, remove, min_remove, buffer);
	}
	else
	{
		buffer[index] = c;
		print_solution(str, index + 1, open, close, remove, min_remove, buffer);
	}

	if (c == '(' || c == ')')
	{
		buffer[index] = ' ';
		print_solution(str, index + 1, open, close, remove + 1, min_remove, buffer);
	}
}

int	count(char *str)
{
	int i = 0;
	int open = 0;
	int close = 0;

	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char	*str = argv[1];
	int	min_remove = count(str);
	char buffer[256];
	print_solution(str, 0, 0, 0, 0, min_remove, buffer);
	return (0);
}