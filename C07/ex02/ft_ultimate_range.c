/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:49:49 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/25 12:39:27 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	res;
	int	*arr;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	res = max - min;
	arr = (int *)malloc(sizeof(int) * res);
	if (!arr)
	{
		return (-1);
	}
	while (min < max)
	{
		arr[i] = min++;
		i++;
	}
	*range = arr;
	return (i);
}
