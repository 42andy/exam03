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
		result += (str[i] - 48);
		i++;
	}
	return (result);
}

int	isprime(int x)
{
	int	i;

	i = 2;
	while (i < x)
	{
		if (x % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	addprime(int x)
{
	int	i;
	int	sum;

	i = 2;
	sum = 0;
	while (i <= x)
	{
		if (isprime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_put(addprime(ft_atoi(argv[1])));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
