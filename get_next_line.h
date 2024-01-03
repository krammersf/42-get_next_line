/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:31:44 by fde-carv          #+#    #+#             */
/*   Updated: 2023/05/18 10:42:44 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> // manipulate fd
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*  *** GET_NEXT_LINE *** */
char	*get_str(int fd, char *str);
char	*get_theline(char *str);
char	*get_new_str(char *str);
char	*get_next_line(int fd);
/*  *** UTILS *** */
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
#endif

/*
> This function requires a filedescriptor and return the next line.
> parameter > fd File Descriptor 
> return > Next line in the file or NULL.
*/
