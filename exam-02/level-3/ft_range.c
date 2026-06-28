#include <stdio.h>
#include <stdlib.h>
int	absolute_number(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
int	*ft_range(int start, int end)
{
	int	size = absolute_number(start - end) + 1;
	int	*range = malloc(sizeof(int) * (size));

	if (!range)
		return (NULL);
	int	i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = start + i;
		else if (start > end)
			range[i] = start - i;
		i++;
	}
	return (range);
}

// int main(void)
// {
// 	int	start = 3;
// 	int	end = 7;
// 	int	*range = ft_range(start, end);
// 	int	size = abs(end - start) + 1;

// 	if (!range)
// 	{
// 		printf("Erro ao alocar memória.\n");
// 		return (1);
// 	}

// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d ", range[i]);
// 	}
// 	printf("\n");

// 	free(range);
// 	return 0;
// }
