#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	nbr1;
	int	nbr2;
	int	n;

	if (argc == 3)
	{
		nbr1 = atoi(argv[1]);
		nbr2 = atoi(argv[2]);
		n = nbr1;
		while (n > 0)
		{
			if (nbr1 % n == 0 && nbr2 % n == 0)
			{
				printf("%d", n);
				break;
			}
			n--;
		}
	}
	printf("\n");
}