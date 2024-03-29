/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:05 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/23 08:48:42 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	num;

	num = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (num <= nb / 2)
	{
		if (nb % num == 0 && num != nb)
		{
			return (0);
		}
		num++;
	}
	return (1);
}
