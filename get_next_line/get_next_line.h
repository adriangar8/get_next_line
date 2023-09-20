/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:11:11 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/20 02:27:16 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *mBox);
char	*get_next_line(int fd);
char	*ft_free(char **str);
char	*ft_2free(char **str1, char **str2);

// UTILS //
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *mBox, unsigned int start, size_t max_len);
char	*ft_strdup(char *str);

#endif