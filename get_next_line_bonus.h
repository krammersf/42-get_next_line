/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:53:28 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/18 10:42:32 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> // manipular arquivos e descritores de arquivo
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*  *** GET_NEXT_LINE_BONUS *** */
char	*get_str(int fd, char *str);
char	*get_theline(char *str);
char	*get_new_str(char *str);
char	*get_next_line(int fd);
/*  *** UTILS *** */
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *str);
#endif
