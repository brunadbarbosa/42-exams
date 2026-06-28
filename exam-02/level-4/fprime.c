#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i = 2;
	int	n = atoi(argv[1]);
	
	if(argc == 2)
	{
		while (n >= i)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n != i)
					printf("*");
				n /= i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}
