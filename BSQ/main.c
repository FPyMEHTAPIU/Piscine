/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakinen <amakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:26:01 by amakinen          #+#    #+#             */
/*   Updated: 2024/01/31 17:33:54 by amakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"
#include "ft.h"

void	process_file(const char *path)
{
	t_map		map;
	t_buffer	*buf;

	if (path)
		buf = read_file(path);
	else
		buf = read_stdin();
	if (buf)
	{
		map.grid = 0;
		if (parse_map(buf, &map))
			solve(&map);
		free_buffer(buf);
		free(map.grid);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		process_file(0);
	else
	{
		while (i < argc)
		{
			if (i > 1)
				ft_putchar('\n');
			process_file(argv[i]);
			i++;
		}
	}
}
