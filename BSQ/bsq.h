/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:08:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/31 17:33:54 by amakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		*grid;
	int		num_rows;
	int		num_cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_buffer
{
	char			*data;
	unsigned int	alloc_size;
	unsigned int	content_size;
}	t_buffer;

int			parse_map(t_buffer *buf, t_map *map);
t_buffer	*read_file(const char *file);
t_buffer	*read_stdin(void);
void		solve(t_map *map);
int			square_fits(t_map *map, int y, int x, int size);
void		print_map(t_map *map, int y, int x, int size);
int			is_map_valid(t_buffer *buf, t_map *map, int buf_skip);
t_buffer	*alloc_buffer(unsigned int initial_size);
void		free_buffer(t_buffer *buf);
void		grow_buffer_if_full(t_buffer *buf);

#endif
