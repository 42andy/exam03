#include <unistd.h>

void	strcap(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	write(1, &str[i], 1);
	i++;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] == 32 || str[i - 1] == 9)
				str[i] -= 32;
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		while (i < argc)
		{
			strcap(argv[i]);
			i++;
		}
	}
}