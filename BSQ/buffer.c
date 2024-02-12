/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:20 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/31 13:20:36 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"
#include <limits.h>
#include <stdlib.h>

t_buffer	*alloc_buffer(unsigned int initial_size)
{
	t_buffer	*buf;

	buf = malloc(sizeof(*buf));
	if (!buf)
		return (0);
	buf->data = (char *)malloc(sizeof(char) * initial_size);
	if (!buf->data)
	{
		free(buf);
		return (0);
	}
	buf->content_size = 0;
	buf->alloc_size = initial_size;
	return (buf);
}

void	free_buffer(t_buffer *buf)
{
	if (buf)
		free(buf->data);
	free(buf);
}

void	grow_buffer_if_full(t_buffer *buf)
{
	char			*new_buffer;
	unsigned int	new_size;
	unsigned int	i;

	if (buf->content_size < buf->alloc_size)
		return ;
	new_size = buf->alloc_size * 2;
	if (buf->alloc_size > UINT_MAX / 2)
		new_size = UINT_MAX;
	new_buffer = (char *)malloc(sizeof(char) * new_size);
	if (new_buffer)
	{
		i = 0;
		while (i < buf->alloc_size)
		{
			new_buffer[i] = buf->data[i];
			i++;
		}
	}
	free(buf->data);
	buf->data = new_buffer;
	buf->alloc_size = new_size;
}
