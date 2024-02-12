/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:56:19 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/31 17:33:54 by amakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"
#include "ft.h"

int	get_params(t_buffer *buf, t_map *map)
{
	unsigned int	length;
	unsigned int	digit_idx;
	unsigned int	num;

	length = 0;
	digit_idx = 0;
	num = 0;
	while (length < buf->content_size && buf->data[length] != '\n')
		length++;
	length++;
	if (length < 5)
		return (0);
	map->full = buf->data[length - 2];
	map->obstacle = buf->data[length - 3];
	map->empty = buf->data[length - 4];
	while ((buf->data[digit_idx] >= '0' && buf->data[digit_idx] <= '9')
		&& digit_idx < (length - 4) && buf->data[0] != '0')
	{
		num = num * 10 + buf->data[digit_idx] - '0';
		digit_idx++;
	}
	if (digit_idx != length - 4)
		return (0);
	map->num_rows = num;
	return (length);
}

void	fill_grid(t_buffer *buf, t_map *map, int buf_skip)
{
	int		row;
	int		col;
	int		obs_above;
	int		obs_on_row;
	int		buf_idx;

	row = 0;
	while (row < map->num_rows)
	{
		col = 0;
		obs_on_row = 0;
		while (col < map->num_cols)
		{
			buf_idx = row * (map->num_cols + 1) + col;
			if (buf->data[buf_skip + buf_idx] == map->obstacle)
				obs_on_row++;
			obs_above = 0;
			if (row > 0)
				obs_above = map->grid[(row - 1) * map->num_cols + col];
			map->grid[row * map->num_cols + col] = obs_on_row + obs_above;
			col++;
		}
		row++;
	}
}

int	parse_map(t_buffer *buf, t_map *map)
{
	int	skip;

	skip = get_params(buf, map);
	if (!skip || !ft_isprint(map->full) || !ft_isprint(map->obstacle)
		|| !ft_isprint(map->empty))
	{
		ft_putstr("map error\n");
		return (0);
	}
	map->num_cols = is_map_valid(buf, map, skip);
	if (!map->num_cols)
	{
		ft_putstr("map error\n");
		return (0);
	}
	map->grid = malloc(sizeof(*map->grid) * map->num_cols * map->num_rows);
	if (!map->grid)
	{
		ft_putstr("Malloc error!\n");
		return (0);
	}
	fill_grid(buf, map, skip);
	return (1);
}
