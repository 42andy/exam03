#include <stdlib.h>

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (ft_abs(start - end) + 1));
	if (!tab)
		return (NULL);
	if (start < end)
	{
		while (start <= end)
		{
			tab[i] = start;
			start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (start >= end)
		{
			tab[i] = start;
			start--;
			i++;
		}
	}
	return (tab);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	int	arr_len;
	int	*arr;

	arr_len = ft_abs(atoi(argv[2]) - atoi(argv[1]));
	arr = ft_range(atoi(argv[1]), atoi(argv[2]));
	for (int i = 0; i <= arr_len; i += 1)
		printf("%d\n", arr[i]);
	free(arr);
	return (EXIT_SUCCESS);
}
*/