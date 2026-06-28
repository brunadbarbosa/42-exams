#include <unistd.h>
int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		
		int	params = argc - 1;
		char	c = params + '0';
		write (1, &c, 1);
	}
	else
		write (1, "0\n", 2);
	return (0);
}
