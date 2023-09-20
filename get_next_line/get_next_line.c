/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:29:33 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/20 02:33:02 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
/*
[Description ft_free]
	1- Free the str memory
	2- Make Null the new value of str
	3- Return NULL
*/

char	*ft_2free(char **str1, char **str2)
{
	free(*str1);
	free(*str2);
	*str1 = NULL;
	*str2 = NULL;
	return (NULL);
}
/*
[Description ft_free]
	1- Free the str1 & str2 memory
	2- Make Null the new value of str & str2
	3- Return NULL
*/

char	*ft_read(int fd, char *mBox)
{
	int		bytes;
	char	*buffer;

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
			return (ft_2free(&mBox, &buffer));
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
	int		cont_a;
	int		cont_b;
	char	*temp;

	cont_a = 0;
	cont_b = 0;
	if (!mBox)
		return (NULL);
	while (mBox[cont_a] && mBox[cont_a] != '\n')
		cont_a++;
	if (!mBox[cont_a])
		return (ft_free(&mBox));
	if (mBox[cont_a] == '\n')
		cont_a++;
	temp = malloc(sizeof(char) * (ft_strlen(mBox) - cont_a + 1));
	if (!temp)
		return (ft_free(&mBox));
	while (mBox[cont_a])
		temp[cont_b++] = mBox[cont_a++];
	temp[cont_b] = '\0';
	free(mBox);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*box = NULL;
	char		*line;
	int			i;

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
		return (ft_2free(&box, &line));
	box = ft_cut(box);
	return (line);
}

/*
[Description get_next_line]
	1-Check if the fd or the BUFFER_SIZE are <0
		{If its}
			a-Return NULL
	2-Read the fd and put inside of the string static
	3-Check if the static exist
	4-Iterate while container have content and its not a \n
	5-With the firts \n detection, put the rest inside a temp string
	6-Cut the line from the static and put inside again
	7- Check if line[0] exist
		{If doesn't}
			a-Free line and static
	8- Return line

[Description ft_read]
	1- Create a mallow and check if its exist
		{If doesn't}
			a- Return Null
	2- Iterate if bytes != 0 and the buffer are not an '\n'
		- Every run save in the variable the fd read count,
		   and check if the bytes readed > 0
			{If its}
				-Close the buffer and add the content to the string box
			{If doesn't}
				-Clean the strs memory

[Description ft_cut]
	1-Iterate while str exist and its not a \n
		-Save counter (this save where is the \n)
	2-Check if Str[cont] stills exist
		{If doesn't}
			a- free str and return NULL
	3-Check if Str[cont] its equalt to \n
		{If its}
			a- iterate cont
	4- Create and check malloc size of len_str - cont(+1 for \0)
	5-Iterate while str[cont] exist and put the content in a temp str
	6- Out of the iteration close the temp
	7- Free the str and return temp


*/