/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:26 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/18 10:42:41 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_str(int fd, char *str)
{
	char		*tab;
	char		*tmp;
	int			read_bytes;

	tab = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!tab)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_strchr(tab, '\n')))
	{
		read_bytes = read(fd, tab, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			if (str)
				free(str);
			free(tab);
			return (NULL);
		}
		tab[read_bytes] = '\0';
		tmp = ft_strjoin(str, tab);
		free(str);
		str = tmp;
	}
	free(tab);
	return (str);
}

char	*get_theline(char *str)
{
	char	*result;
	int		i;

	i = 0;
	if (!(str[i]))
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	result = ft_calloc(sizeof(char), (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{	
		result[i] = str[i];
		i++;
	}
	else
		result[i] = '\0';
	return (result);
}

char	*get_new_str(char *str)
{
	char	*new_str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!(str[i] == '\n'))
	{
		free(str);
		return (NULL);
	}
	new_str = ft_calloc(sizeof(char), (ft_strlen(str) - i));
	if (!new_str)
		return (NULL);
	i++;
	while (str[i] != '\0')
	{
		new_str[count] = str[i];
		count++;
		i++;
	}
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char		*str[FOPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	str[fd] = get_str(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_theline(str[fd]);
	str[fd] = get_new_str(str[fd]);
	return (line);
}

/*
int	main(void)
{
	int	fd;
	char	*line;
	int	i;
	
	fd = open("fred2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR ON FILE");
		return (0);
	}
	i = 0;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
*/

/*
Essa é uma função que lê um arquivo de texto linha por linha, a partir de um
descritor de arquivo ("fd"). A função utiliza outras três funções auxiliares:
"get_str()", "get_theline()" e "get_new_str()".

A variável "str" é uma matriz estática de ponteiros para caracteres, que
armazena o conteúdo do arquivo lido. A matriz tem o tamanho máximo de arquivos
abertos simultaneamente ("FOPEN_MAX", definido em "stdio.h").

FOPEN_MAX representa o número máximo de arquivos que podem ser abertos
simultaneamente por um programa. É um valor que depende da implementação e
pode variar entre sistemas operacionais ou ambientes de desenvolvimento.
Em geral, seu valor é grande o suficiente para atender às necessidades da maioria
dos programas, como 256 ou 1024.
*/
