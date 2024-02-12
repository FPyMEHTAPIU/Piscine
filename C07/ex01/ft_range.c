/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:14:54 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/25 11:22:14 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	while (min < max)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}
