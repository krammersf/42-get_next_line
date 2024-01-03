/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:31:41 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/18 10:42:16 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (str[i] == '\0')
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
	if (str[i] == '\0')
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
	static char		*str;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_str(fd, str);
	if (!str)
		return (NULL);
	line = get_theline(str);
	str = get_new_str(str);
	return (line);
}

/*
int	main(void)
{
	int	i;
	int	fd;
	char	*line;

	fd = open("fred5.txt", O_RDONLY);
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
Este código é usado para ler linhas de um arquivo de texto (fd representa
o descritor de arquivo correspondente). A função usa um buffer para ler do
arquivo em partes e armazena o conteúdo lido numa variável str. Em seguida,
a função get_theline é usada para extrair a primeira linha da variável str
e armazená-la em uma variável line. A função get_new_str é usada para
atualizar a variável str, removendo a linha que já foi lida. A função
get_next_line retorna a linha lida ou NULL se houver erro.

> ft_calloc aloca memória e inicializa-a com zero.
> ft_strchr encontra a primeira ocorrência de um caractere numa string.
> ft_strlen retorna o tamanho de uma string.
> ft_strjoin concatena duas strings.
Estas funções são usadas para manipular as strings durante a leitura e a
extração das linhas do arquivo.

É importante notar que o código usa uma variável static char *str para
armazenar o conteúdo lido do arquivo entre chamadas sucessivas da função
get_next_line. Isso significa que a função get_next_line pode ser chamada
várias vezes para ler linhas sucessivas de um arquivo sem precisar reabrir
o arquivo a cada chamada. No entanto, isso também significa que a função não
é segura para uso simultâneo em vários threads, pois a variável static será
compartilhada entre todos eles.
*/
