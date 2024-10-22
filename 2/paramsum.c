#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &base[nb % 10], 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
}