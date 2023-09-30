/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:59:22 by rruiz-sa          #+#    #+#             */
/*   Updated: 2023/09/27 11:17:08 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

// defaut buffer size //
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// basic functions //
char	*get_next_line(int fd);
char	*ft_free(char **str);

// utils functions //
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
