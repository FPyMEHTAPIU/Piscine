/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:31:32 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/22 11:34:20 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	num = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb <= 1)
	{
		return (num);
	}
	while (nb > 1)
	{
		num *= nb--;
	}
	return (num);
}
