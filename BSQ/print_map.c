/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakinen <amakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:37:51 by amakinen          #+#    #+#             */
/*   Updated: 2024/01/30 16:06:28 by amakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

/*
	A size one square can fit into any location that doesn't have an obstacle.
	We can this fact to recover obstacle locations from our preprocessed map.
*/
static int	has_obstacle(t_map *map, int y, int x)
{
	return (!square_fits(map, y, x, 1));
}

void	print_map(t_map *map, int sq_y, int sq_x, int sq_size)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->num_rows)
	{
		x = 0;
		while (x < map->num_cols)
		{
			if (has_obstacle(map, y, x))
				ft_putchar(map->obstacle);
			else if (
				x >= sq_x
				&& x < sq_x + sq_size
				&& y >= sq_y
				&& y < sq_y + sq_size)
				ft_putchar(map->full);
			else
				ft_putchar(map->empty);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
