/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:55:11 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/29 19:56:05 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static size_t	get_file_size(int fd)
{
	ssize_t		read_ret;
	char		buffer[550];

	read_ret = 0;
	if ((read_ret = read(fd, buffer, sizeof(buffer))) == -1)
		exit(EXIT_FAILURE);
	return ((size_t)read_ret);
}

static void		store_file_content(char *file_content, int fd, size_t size_file)
{
	if (read(fd, file_content, size_file) == -1)
		exit(EXIT_FAILURE);
	file_content[size_file] = '\0';
}

char			*get_file_content(char *pathname)
{
	char	*file_content;
	int		fd;
	size_t	size_file;

	if ((fd = open(pathname, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	size_file = get_file_size(fd);
	close(fd);
	if ((file_content = malloc(size_file + 1)) == NULL)
		exit(EXIT_FAILURE);
	if ((fd = open(pathname, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	store_file_content(file_content, fd, size_file);
	close(fd);
	return (file_content);
}
