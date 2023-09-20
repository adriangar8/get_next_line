/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:28:50 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/20 02:05:21 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *mBox, unsigned int start, size_t max_len)
{
	char	*aux;
	size_t	count;
	size_t	len_str;

	count = 0;
	if (!mBox)
		return (0);
	len_str = ft_strlen(mBox);
	if (max_len >= len_str - start && start < len_str)
		max_len = len_str - start;
	else if (start >= len_str)
		max_len = 0;
	else if (max_len > len_str)
		max_len = len_str;
	aux = malloc(sizeof(char) * (max_len + 1));
	if (!aux)
		return (0);
	while (count < max_len)
		aux[count++] = mBox[start++];
	aux[count] = '\0';
	return (aux);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*aux;
	int		count;
	int		aux_count;

	count = -1;
	aux_count = 0;
	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
	aux = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!aux)
		return (ft_free(&str1));
	while (str1[++count])
		aux[count] = str1[count];
	while (str2[aux_count])
		aux[count++] = str2[aux_count++];
	aux[count] = '\0';
	free(str1);
	return (aux);
}

char	*ft_strchr(char *str, int c)
{
	int		count;

	count = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)(str + count));
	while (str[count] != '\0')
	{
		if (str[count] == (char)c)
			return ((char *)(str + count));
		count++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	char	*aux;
	int		count;
	int		len;

	count = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	aux = (char *)malloc(sizeof(char) * (len + 1));
	if (!aux)
	{
		free(str);
		return (NULL);
	}
	while (str[count] != '\0')
	{
		aux[count] = *((char *)(str + count));
		count++;
	}
	aux[count] = '\0';
	return (aux);
}
