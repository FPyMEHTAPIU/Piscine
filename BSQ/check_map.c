/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:44:55 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/31 17:35:04 by amakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

int	check_characters(t_buffer *buf, t_map *map, unsigned int buf_skip)
{
	unsigned int	i;

	i = buf_skip;
	while (i < buf->content_size)
	{
		if (buf->data[i] != map->empty && buf->data[i] != map->obstacle \
			&& buf->data[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_line_length(t_buffer *buf, int *num_lines, unsigned int buf_skip)
{
	int				length_first;
	int				length_others;
	unsigned int	i;

	length_first = 0;
	length_others = 0;
	i = buf_skip;
	while (i < buf->content_size && buf->data[i++] != '\n')
		length_first++;
	while (i < buf->content_size)
	{
		if (buf->data[i] == '\n')
		{
			if (length_first != length_others)
				return (0);
			length_others = 0;
			(*num_lines)++;
		}
		else
			length_others++;
		i++;
	}
	return (length_first);
}

int	is_map_valid(t_buffer *buf, t_map *map, int buf_skip)
{
	int	num_lines;
	int	line_length;

	num_lines = 1;
	if (!check_characters(buf, map, buf_skip))
		return (0);
	line_length = check_line_length(buf, &num_lines, buf_skip);
	if (!line_length)
		return (0);
	if (num_lines != map->num_rows || map->empty == map->full
		|| map->empty == map->obstacle || map->full == map->obstacle)
		return (0);
	return (line_length);
}
