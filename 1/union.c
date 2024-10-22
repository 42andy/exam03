#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;
	int	tab[256] = {0};

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (tab[(int)argv[1][i]] == 0)
			{
				write(1, &argv[1][i], 1);
				tab[(int)argv[1][i]] = 1;
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (tab[(int)argv[2][i]] == 0)
			{
				write(1, &argv[2][i], 1);
				tab[(int)argv[2][i]] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}