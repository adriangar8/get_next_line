/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:29:33 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/18 10:58:26 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_2free(char **str1, char **str2)
{
	free(*str1);
	free(*str2);
	*str1 = NULL;
	*str2 = NULL;
	return (NULL);
}
char	*ft_read(int fd, char *mBox);
{
	int			byte;
	char		*buffer;

	bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(mBox);
		return (NULL);
	}
	buffer[0] = '\0';
	while (bytes > 0 && !ft_strchr(mBox, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free_double(&mBox, &buffer));
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			mBox = ft_strjoin(mBox, buffer);
		}
	}
	free(buffer);
	return (mBox);
}

char	*ft_cut(char *mBox)
{
	int		count1;
	int		count2;
	char	*aux;

	count1 = 0;
	count2 = 0;
	if (!mBox)
		return (NULL);
	while (mBox[count1] && mBox[count1] != '\n')
		count1++;
	if (!mBox[count1])
		return (ft_free(&mBox));
	if (mBox[count1] == '\n')
		count1++;
	aux = malloc(sizeof(char) * (ft_strlen(mBox) - count1 + 1));
	if (!aux)
		return (ft_free(&mBox));
	while (mBox[count1])
		aux[count2++] = mBox[count1++];
	aux[count2] = '\0';
	free(mBox);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char		*box;
	char			*line;
	int				i;

	box = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!box || (box && !ft_strchr(box, '\n')))
		box = ft_read(fd, box);
	if (!box)
		return (NULL);
	while (box[i] && box[i] != '\n')
		i++;
	line = ft_substr(box, 0, i + 1);
	if (!line || !line[0])
		return (ft_free_double(&box, &line));
	box = ft_cut(box);
	return (line);
}
