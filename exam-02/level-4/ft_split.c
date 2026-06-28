#include <stdlib.h>
#include <stdio.h>
int	ft_count_words(char *str)
{
	int	i = 0;
	int	count = 0;
	
	while (str[i])
	{
		if(str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			count++;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				i++;
		}
		else
			i++;
	}
	return (count);
}
	
char	**ft_split(char *str)
{
	char	**the_split = malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!the_split)
		return (NULL);
	int	i = 0;
	int	j = 0;
	int	k;
	int	l;
	
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			l = 0;
			while (str[i + l] && (str[i + l] != ' ' && str[i + l] != '\t'))
				l++;
			the_split[j] = malloc(sizeof(char) * (l + 1));
			if (!the_split[j])
				return (NULL);
			k = 0;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				the_split[j][k++] = str[i++];
			the_split[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	the_split[j] = NULL;
	return (the_split);
}		

int	main(int argc, char **argv)
{
	char	**result = ft_split(argv[1]);
	int		i = -1;

	(void)argc;
	while (result[++i])
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}
