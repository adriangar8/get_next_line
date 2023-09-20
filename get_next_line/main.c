/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:26:06 by adrian            #+#    #+#             */
/*   Updated: 2023/09/20 01:34:11 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int	main(void)
{
	int	fd;

	fd = open("try.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
