#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put(int x)
{
	if (x > 9)
	{
		ft_put(x / 10);
		ft_put(x % 10);
	}
	else
		ft_putchar(x + 48);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	nb;

	i = 1;
	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		while (i <= 9)
		{
			ft_put(i);
			write(1, " x ", 3);
			ft_put(nb);
			write(1, " = ", 3);
			ft_put(i * nb);
			if (i < 9)
				write(1, "\n", 1);
			i++;
		}
		
	}
	write(1, "\n", 1);
}
