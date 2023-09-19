/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:28:50 by adrigarc          #+#    #+#             */
/*   Updated: 2023/09/19 12:36:47 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *mBox, unsigned int start, size_t len_max)
{
	char	*aux;
	size_t	count;
	size_t	len_str;

	count = 0;
	if (!mBox)
		return (0);
	len_str = ft_strlen(mBox);
	if (len_max >= len_str - start && start < len_str)
		len_max = len_str - start;
	else if (start >= len_str)
		len_max = 0;
	else if (len_max > len_str)
		len_max = len_str;
	aux = malloc(sizeof(char) * (len_max + 1));
	if (!aux)
		return (0);
	while (count < len_max)
		aux[count++] = mBox[start++];
	aux[count] = '\0';
	return (aux);
}
