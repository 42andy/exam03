#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h> // Pour malloc, free
#include <unistd.h> // Pour read, write, close
#include <fcntl.h>  // Pour open

#define BUFFER_SIZE 1024

// Fonction ft_strchr corrigée
char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == (char)c)
			return (s + i);
	}
	if (c == '\0')
		return (s + i);
	return (NULL);
}

// Fonction ft_memcpy corrigée
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	for (i = 0; i < n; i++)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

// Fonction ft_strlen corrigée
size_t	ft_strlen(char *s)
{
	size_t	ret;

	ret = 0;
	if (!s)
		return (0);
	while (s[ret])
		ret++;
	return (ret);
}

// Fonction str_append_mem corrigée
int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(*s1);
	tmp = malloc(size1 + size2 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return (1);
}

// Fonction str_append_str corrigée
int	str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

// Fonction ft_memmove_custom corrigée
void	*ft_memmove_custom(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		for (size_t i = 0; i < n; i++)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}

// Fonction get_next_line corrigée
char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp;
	int		read_ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		tmp = ft_strchr(b, '\n');
		if (tmp)
		{
			if (!str_append_mem(&ret, b, tmp - b + 1))
				return (free(ret), NULL);
			ft_memmove_custom(b, tmp + 1, ft_strlen(tmp + 1));
			b[ft_strlen(tmp + 1)] = '\0';
			return (ret);
		}
		if (!str_append_str(&ret, b))
			return (free(ret), NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(ret), NULL);
		if (read_ret == 0)
		{
			b[0] = '\0'; // Réinitialiser le buffer après la fin du fichier
			break;
		}
		b[read_ret] = '\0';
	}
	if (ret && ret[0] != '\0')
		return (ret);
	free(ret);
	return (NULL);
}


int	main(void)
{
	int		fd;
	char	*line;
	size_t	len;

	// Ouvrir le fichier "test.txt" en lecture seule
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1); // Retourner une erreur si l'ouverture échoue

	// Lire et afficher chaque ligne du fichier
	while ((line = get_next_line(fd)) != NULL)
	{
		len = ft_strlen(line);
		if (len > 0)
			write(1, line, len);
		free(line); // Libérer la mémoire allouée par get_next_line
	}

	// Fermer le fichier
	if (close(fd) < 0)
		return (1); // Retourner une erreur si la fermeture échoue

	return (0);
}
