/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:26:06 by adrian            #+#    #+#             */
/*   Updated: 2023/09/27 11:08:49 by adrigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

/*
int	main(void)
{
	int	fd;

	fd = open("try.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
*/

int	main(void)
{
	int		tmp_fd = open("tempfile", O_RDWR | O_CREAT, 0644);
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
		write(tmp_fd, buffer, bytes_read);
	}
	lseek(tmp_fd, 0, SEEK_SET);
	close(tmp_fd);
	printf("%s\n", get_next_line(tmp_fd));
	return (0);
}
