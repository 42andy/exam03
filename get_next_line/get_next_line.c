#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	line[7000000];
	int		b;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	b = read(fd, &buffer, 1);
	while (b > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		b = read(fd, &buffer, 1);
	}
	line[i] = '\0';
	if (b <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(line));
}