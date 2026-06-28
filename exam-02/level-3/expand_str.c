#include <unistd.h>
int count_words(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
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
int main(int argc, char **argv)
{
    int i = 0;
	int words = 0;
    int count = count_words(argv[1]);
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                words++;
				while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
				{
					write (1, &argv[1][i], 1);
					i++;
				}
				if (words < count)
					write (1, "   ", 3);
            }
			else
				i++;      
        }
    }
    write (1, "\n", 1);
    return (0);
}