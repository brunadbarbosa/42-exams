#include <stdio.h>
#include <stdlib.h>
int	absolute_number(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
int	*ft_rrange(int start, int end)
{
	int	size = absolute_number(end - start) + 1;
	int	*range = malloc(sizeof(int) * (size));
	if (!range)
		return (NULL);
	int	i = 0; //3
	while (i <= size)
	{
		if (start <= end)
			range[i] = end - i;
		else if (end < start)
			range[i] = end + i;
		i++;
	}
	return (range);
}

/*int main(void)
{
	int	start = 1;
	int	end = 3;
	int	*range = ft_rrange(start, end);
	int	size = abs(end - start) + 1;

	if (!range)
	{
		printf("Erro ao alocar memória.\n");
		return (1);
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", range[i]);
	}
	printf("\n");

	free(range);
	return 0;
}*/
