#include <unistd.h>
#include <string.h>
#include <stdio.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

void	ft_filter(char *str, char *s)
{
	int	h = 0;
	int len_s = strlen(s);
	int i = 0;
	int l = 0;

	while (str[i])
	{
		h = 0;
		while (s[h] && s[h] == str[i + h])
			h++;
		if (h == len_s)
		{
			l = 0;
			while (l < len_s)
			{
				write(1, "*", 1);
				l++;
			}
			i += h;
		}
		else
		{
			write (1, &str[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int	r = 1;
	int f = 0;
	char line[999999];

	while (r > 0)
	{
		r = read(0, &line[f], BUFFER_SIZE);
		if (r < 0)
		{
			perror("read");
			return (1);
		}
		f += r;
	}
	ft_filter(line, argv[1]);
	return(0);
}