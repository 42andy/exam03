#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	print_hex(int nb)
{
	if (nb >= 16)
	{
		print_hex(nb / 16);
		print_hex(nb % 16);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else if (nb < 16)
		ft_putchar(nb + 87);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}