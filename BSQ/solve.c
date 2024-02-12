/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakinen <amakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:00:06 by amakinen          #+#    #+#             */
/*   Updated: 2024/01/31 16:54:31 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

/*
	Preprocessed grid counts the number of obstacles "before", that is, above
	and to the left of each position. First row and column obviously can't have
	obstacles before them so they aren't stored, and obstacles in the last row
	or column are queried with y or x equal to the grid dimensions.
*/
static int	num_obstacles_before(t_map *map, int y, int x)
{
	if (x == 0 || y == 0)
		return (0);
	return (map->grid[(y - 1) * map->num_cols + x - 1]);
}

/*
	If the square is not blocked by an obstacle, the number of obstacles
	"before" its bottom and right edges is the same as the number of obstacles
	"before" its left and top edges. If there are obstacles, the count is
	higher. Topleft area is counted twice, by both top(right) and (bottom)left,
	so it is subtracted again from the sum.
*/
int	square_fits(t_map *map, int y, int x, int size)
{
	int	obs_topleft;
	int	obs_topright;
	int	obs_botleft;
	int	obs_botright;

	if (y + size > map->num_rows)
		return (0);
	if (x + size > map->num_cols)
		return (0);
	obs_topleft = num_obstacles_before(map, y, x);
	obs_topright = num_obstacles_before(map, y, x + size);
	obs_botleft = num_obstacles_before(map, y + size, x);
	obs_botright = num_obstacles_before(map, y + size, x + size);
	return (obs_botright == obs_topright + obs_botleft - obs_topleft);
}

/*
	Try to make a larger square than before in each position, and if successful
	mark the new biggest square's starting position. If the map is valid it has
	at minimum one empty position which can be used for a size 1 square. We
	double check here, but validation is done and error message is printed
	during map parsing.
*/
static void	find_largest_sq(t_map *map, int *largest_size, int *sq_y, int *sq_x)
{
	int	try_y;
	int	try_x;

	*largest_size = 0;
	*sq_y = 0;
	*sq_x = 0;
	try_y = 0;
	while (try_y + *largest_size <= map->num_rows)
	{
		try_x = 0;
		while (try_x + *largest_size <= map->num_cols)
		{
			while (square_fits(map, try_y, try_x, *largest_size + 1))
			{
				(*largest_size)++;
				*sq_y = try_y;
				*sq_x = try_x;
			}
			try_x++;
		}
		try_y++;
	}
}

void	solve(t_map *map)
{
	int	largest_size;
	int	sq_y;
	int	sq_x;

	find_largest_sq(map, &largest_size, &sq_y, &sq_x);
	if (largest_size > 0)
		print_map(map, sq_y, sq_x, largest_size);
	else
		ft_putstr("map error\n");
}
