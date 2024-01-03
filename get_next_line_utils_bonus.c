/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:31 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/18 10:42:22 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	while (*str != '\0' && *str != c)
		str++;
	if (c == *str)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len;
	int		i;
	int		j;

	len = (ft_strlen(s1) + ft_strlen(s2));
	new_str = ft_calloc(sizeof(char), (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{	
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	int		total_size;

	total_size = nmemb * size;
	tab = malloc(total_size);
	if (!tab)
		return (NULL);
	while (--total_size >= 0)
		tab[total_size] = '\0';
	return ((void *)tab);
}
