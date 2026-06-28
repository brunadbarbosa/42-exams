
#include <stdlib.h>
#include <unistd.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	//pointer check
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	
	//pipe
	int	fd[2];
	if (pipe(fd) == -1)
		return (-1);
	
	//fork
	pid_t pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}

	//child
	if (pid == 0)
	{
		//dup
		if (type == 'r')
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(-1);
			close(fd[1]);
		}
		else if (type == 'w')
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit(-1);
			close(fd[0]);
		}

		//execvp
		execvp(file, argv);
		exit(-1);
	}

	//parent
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	close(fd[0]);
	return (fd[1]);
}

#include <string.h>

int	main()
{
	char	line[1001];
	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	int	len = read(fd, line, 1000);
	line[len] = '\0';
	write(STDOUT_FILENO, line, strlen(line));
	close(fd);
	return (0);
}