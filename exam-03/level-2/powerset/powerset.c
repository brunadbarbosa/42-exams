#include <stdlib.h>
#include <stdio.h>

void	print_subset(int *arr, int *path, int len)
{
	int	i = 0;
	int	first = 1;

	while (i < len)
	{
		if (path[i])
		{
			if (!first)
				printf(" ");
			printf("%d", arr[i]);
			first = 0;
		}
		i++;
	}
	printf("\n");
}

void	backtrack(int *arr, int *path, int len, int index, int sum, int target)
{
	if (index == len)
	{
		if (sum == target)
			print_subset(arr, path, len);
		return ;
	}

	path[index] = 1;
	backtrack(arr, path, len, index + 1, sum + arr[index], target);
	path[index] = 0;
	backtrack(arr, path, len, index + 1, sum, target);
}
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int	target = atoi(argv[1]);
	int len = argc - 2;
	int	*arr = malloc(sizeof(int) * len);
	int *path = calloc(len, sizeof(int));
	int	i = -1;
	if(!arr || !path)
		return(1);
	while(++i < len)
		arr[i] = atoi(argv[i + 2]);
	backtrack(arr, path, len, 0, 0, target);
	free(arr);
	free(path);
	return (0);
}