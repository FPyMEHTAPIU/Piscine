/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:46:14 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/23 08:49:17 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//timeout :D but works

int	ft_find_next_prime(int nb)
{
	int	num;

	num = 2;
	if (nb <= 1)
	{
		return (num);
	}
	while (num <= nb / 2)
	{
		if (nb % num == 0)
		{
			nb++;
			num = 2;
		}
		num++;
	}
	return (nb);
}
