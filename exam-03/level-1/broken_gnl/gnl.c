#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*ft_strdup(char *str)
{
	int	size = 0;
	int	i = 0;
	while (str[size])
		size++;
	char	*line = malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL);
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int	bytes_read = 0;
	static int buffer_position = 0;
	int	i = 0;
	char line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (bytes_read == buffer_position)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_position = 0;
			if (bytes_read < 0)
				return (NULL);
			if (bytes_read == 0)
				break ;
		}
		line[i++] = buffer[buffer_position++];
		if (line[i - 1] == '\n' || !line[i - 1])
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("teste.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return(0);
}