/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakinen <amakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:48 by amakinen          #+#    #+#             */
/*   Updated: 2024/01/31 17:04:47 by amakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"
#include "ft.h"

t_buffer	*read_fd(int fd)
{
	ssize_t		bytes_read;
	t_buffer	*buf;

	bytes_read = 1;
	buf = alloc_buffer(4096);
	while (bytes_read > 0)
	{
		if (!buf || !buf->data)
		{
			free_buffer(buf);
			ft_putstr("Malloc error!\n");
			return (0);
		}
		bytes_read = read(fd, buf->data + buf->content_size,
				buf->alloc_size - buf->content_size);
		if (bytes_read == -1)
		{
			free_buffer(buf);
			ft_putstr("Error with read!\n");
			return (0);
		}
		buf->content_size += bytes_read;
		grow_buffer_if_full(buf);
	}
	return (buf);
}

t_buffer	*read_file(const char *file)
{
	int			fd;
	t_buffer	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error with open (file name: ");
		ft_putstr(file);
		ft_putstr(")\n");
		return (0);
	}
	buf = read_fd(fd);
	close(fd);
	return (buf);
}

t_buffer	*read_stdin(void)
{
	return (read_fd(STDIN_FILENO));
}
