/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:37:44 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/19 10:39:07 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == base[i + 1])
		{
			return (0);
		}
		i++;
	}
	if (i <= 1)
	{
		return (0);
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		tbase;
	char	a;
	long	conv;

	tbase = check_base(base);
	if (tbase)
	{
		conv = (long) nbr;
		if (conv < 0)
		{
			ft_putchar('-');
			conv *= -1;
		}
		if (conv >= tbase)
		{
			ft_putnbr_base(conv / tbase, base);
		}
		a = base[conv % tbase];
		ft_putchar(a);
	}
}
