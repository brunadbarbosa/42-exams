#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int picoshell(char **cmds[])
{
	//pointer check
	if (!cmds)
		return (1);

	int	fd[2];
	int	in_fd = STDIN_FILENO;
	pid_t	pid;

	//iterate through cmds
	for (int i = 0; cmds[i]; i++)
	{
		//pipe
		if (cmds[i + 1])
		{
			if (pipe(fd) == -1)
			{
				if (in_fd != STDIN_FILENO)
					close(in_fd);
				return (1);
			}
		}
		else
		{
			fd[0] = -1;
			fd[1] = -1;
		}

		//fork
		pid = fork();
		if (pid == -1)
		{
			if (in_fd != STDIN_FILENO)
				close(in_fd);
			if (fd[0] != -1)
				close(fd[0]);
			if (fd[1] != -1)
				close(fd[1]);
			return (1);
		}

		//child
		else if (pid == 0)
		{
			//dup
			if (fd[0] != -1)
				close(fd[0]);
			if (in_fd != STDIN_FILENO)
			{
				if (dup2(in_fd, STDIN_FILENO) == -1)
				{
					close(in_fd);
					if (fd[1] != -1)
						close(fd[1]);
					exit(1);
				}
				close(in_fd);
			}
			if (fd[1] != -1)
			{
				if (dup2(fd[1], STDOUT_FILENO) == -1)
				{
					close(fd[1]);
					exit(1);
				}
				close(fd[1]);
			}

			//execute
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}

		//parent
		if (in_fd != STDIN_FILENO)
			close(in_fd);
		if (fd[1] != -1)
			close(fd[1]);
		in_fd = fd[0];
	}

	//wait for children
	int	status;
	while (wait(&status) != -1)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (1);
		if (WIFSIGNALED(status))
			return (1);
	}
	if (errno != ECHILD)
		return (1);
	return (0);
}

int	main(void)
{
	char	*cmd1[] = {"ls", "hello world", NULL};
	char	*cmd2[] = {"grep", "hello", NULL};
	char	*cmd3[] = {"wc", "-c", NULL};

	char	**cmds[] = {cmd1, cmd2, cmd3, NULL};

	if (picoshell(cmds) == 1)
		return (1);
	return (0);
}
